#ifndef MVM_SERVER_H
#define MVM_SERVER_H

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

class MotorServer : public wxAppConsole
{
    public:
        virtual bool OnInit();
        void OnTimerTick(wxTimerEvent& event);

    private:
        wxTimer *m_timer;
        wxDECLARE_EVENT_TABLE();
};

#endif

