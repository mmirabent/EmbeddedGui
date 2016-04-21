#include "server.h"
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
    cout << "Hello world!" << endl;
    startServer();
    return true;
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

    cout << "Accepted incoming connection" << endl;
}

void MotorServer::OnSocketEvent(wxSocketEvent& event)
{
    wxSocketBase *socket = event.GetSocket();

    // Process the event
    switch(event.GetSocketEvent())
    {
        case wxSOCKET_INPUT:
            unsigned char size;

            socket->Read(&size, sizeof(size));

            cout << "Size is " << (unsigned int)size << endl;
            break;
    }
}

wxBEGIN_EVENT_TABLE(MotorServer,wxAppConsole)
    EVT_SOCKET(SERVER_ID,MotorServer::OnServerEvent)
    EVT_SOCKET(SOCKET_ID,MotorServer::OnSocketEvent)
wxEND_EVENT_TABLE()


