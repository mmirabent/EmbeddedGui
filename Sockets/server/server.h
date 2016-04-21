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

enum
{
    STOP_CMD = 0x00,
    START_CMD,
    ROTATE_CMD,
    SPEED_CMD
};

enum
{
    ROTATE_LEFT = 0x00,
    ROTATE_RIGHT
};


#endif

