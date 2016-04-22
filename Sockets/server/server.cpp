#include "server.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

enum
{
    SERVER_ID = 1000,
    SOCKET_ID
};

IMPLEMENT_APP(MotorServer)

bool MotorServer::OnInit()
{
    cout << "Welcome to Motor Server 3000" << endl;
    startServer();
    return true;
}

int MotorServer::OnExit()
{
    m_server->Destroy();
    return 0;
}

void MotorServer::startServer()
{
    wxIPV4address addr;
    addr.Service(3000);

    m_server = new wxSocketServer(addr);

    if(!m_server->Ok())
        return;

    cout << "Listening on address "
         << addr.IPAddress().ToStdString()
         << " at port "
         << addr.Service()
         << endl;

    m_server->SetEventHandler(*this,SERVER_ID);
    m_server->SetNotify(wxSOCKET_CONNECTION_FLAG);
    m_server->Notify(true);
}

void MotorServer::OnServerEvent(wxSocketEvent&)
{
    // Get the socket base from the server
    wxSocketBase* socket = m_server->Accept(false);

    socket->SetEventHandler(*this, SOCKET_ID);
    socket->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
    socket->Notify(true);
}

void MotorServer::OnSocketEvent(wxSocketEvent& event)
{
    wxSocketBase *socket = event.GetSocket();

    // Process the event
    switch(event.GetSocketEvent())
    {
        case wxSOCKET_INPUT:
            struct MotorResponse response;
            struct MotorRequest request;

            socket->Read(&request.size, sizeof(request.size));
            socket->Read(&request.command, sizeof(request.command));
            socket->Read(request.attributes, request.size-2);

            response = processCommand(request);

            socket->Write(&response, sizeof(response));
            break;

        case wxSOCKET_OUTPUT:
        case wxSOCKET_CONNECTION:
        case wxSOCKET_LOST:
            break;
    }
}

struct MotorResponse MotorServer::processCommand(struct MotorRequest req)
{
    struct MotorResponse response;

    switch(req.command)
    {
        case STOP_CMD:
            cout << "Motor Stop" << endl;
            break;

        case START_CMD:
            cout << "Motor Start" << endl;
            break;

        case ROTATE_CMD:
            if(req.attributes[0] == ROTATE_LEFT)
            {
                cout << "Rotate Left" << endl;
            }
            else if(req.attributes[0] == ROTATE_RIGHT)
            {
                cout << "Rotate Right" << endl;
            }
            break;

        case SPEED_CMD:
            cout << "Speed set to "
                 << to_string((uint8_t)req.attributes[0])
                 << endl;
            break;
    }
    response.type = 0x00;
    response.attribute = 0x00;
    return response;
}

wxBEGIN_EVENT_TABLE(MotorServer,wxAppConsole)
    EVT_SOCKET(SERVER_ID,MotorServer::OnServerEvent)
    EVT_SOCKET(SOCKET_ID,MotorServer::OnSocketEvent)
wxEND_EVENT_TABLE()


