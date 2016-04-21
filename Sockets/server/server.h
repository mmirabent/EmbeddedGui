#ifndef MVM_SERVER_H
#define MVM_SERVER_H

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/socket.h"

class MotorServer : public wxAppConsole
{
    public:
        virtual bool OnInit();
        void OnServerEvent(wxSocketEvent& event);
        void OnSocketEvent(wxSocketEvent& event);

    private:
        wxSocketServer *m_server;

        void startServer();

        wxDECLARE_EVENT_TABLE();
};


#endif

