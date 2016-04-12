#ifndef RESULTPOSTEDEVENT_H
#define RESULTPOSTEDEVENT_H

#include <wx/event.h>
#include "URLSearchRecord.h"

class ResultPostedEvent;
wxDECLARE_EVENT(RESULT_POSTED, ResultPostedEvent);

class ResultPostedEvent : public wxEvent
{
    public:
        ResultPostedEvent(wxEventType eventType, int winid, const URLSearchRecord& rec);
        ResultPostedEvent(const ResultPostedEvent& evt);

        virtual wxEvent *Clone() const;
        URLSearchRecord getRec();


    protected:

    private:
        URLSearchRecord rec;
};

#endif // RESULTPOSTEDEVENT_H
