#ifndef MVM_SERVER_H
#define MVM_SERVER_H

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/socket.h"
#include "../motor_protocol.h"

class MotorServer : public wxAppConsole
{
    public:
        virtual bool OnInit();
        virtual int OnExit();
        void OnServerEvent(wxSocketEvent& event);
        void OnSocketEvent(wxSocketEvent& event);

    private:
        wxSocketServer *m_server;

        void startServer();
        struct MotorResponse processCommand(struct MotorRequest request);

        wxDECLARE_EVENT_TABLE();
};


#endif

