#include "server.h"
#include <wx/timer.h>
#include <iostream>

using namespace std;


IMPLEMENT_APP(MotorServer);

bool MotorServer::OnInit()
{
    cout << "Hello world!" << endl;
    m_timer = new wxTimer();
    m_timer->Start(500);
}

void MotorServer::OnTimerTick(wxTimerEvent&)
{
    cout << "Tick" << endl;
}

wxBEGIN_EVENT_TABLE(MotorServer,wxAppConsole)
    EVT_TIMER(wxID_ANY,MotorServer::OnTimerTick)
wxEND_EVENT_TABLE()

