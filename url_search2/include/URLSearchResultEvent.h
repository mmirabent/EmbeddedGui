#ifndef URLSEARCHRESULTEVENT_H
#define URLSEARCHRESULTEVENT_H

#include <wx/event.h>
#include "URLSearchRecord.h"

class URLSearchResultEvent : public wxEvent
{
    public:
        URLSearchResultEvent(wxEventType eventType, int winid, const URLSearchRecord& rec);
        URLSearchRecord getRec();
        virtual wxEvent Clone() const;

    protected:

    private:
};

#endif // URLSEARCHRESULTEVENT_H
