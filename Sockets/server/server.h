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
        struct Response processCommand(unsigned char command,
                                       unsigned char attr[254]);

        wxDECLARE_EVENT_TABLE();
};

struct Response
{
    unsigned char type;
    unsigned char attribute[4];
};


#endif

