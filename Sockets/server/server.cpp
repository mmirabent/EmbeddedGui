#include "server.h"
#include <iostream>

using namespace std;

enum
{
    SERVER_ID = 1000,
    SOCKET_ID
};

IMPLEMENT_APP(MotorServer);

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

void MotorServer::OnServerEvent(wxSocketEvent& event)
{
    cout << "Accepted incoming connection" << endl;
}


wxBEGIN_EVENT_TABLE(MotorServer,wxAppConsole)
    EVT_SOCKET(SERVER_ID,MotorServer::OnServerEvent)
wxEND_EVENT_TABLE()


