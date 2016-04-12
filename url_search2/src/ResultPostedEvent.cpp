#include "ResultPostedEvent.h"

ResultPostedEvent::ResultPostedEvent(wxEventType eventType, int winid, const URLSearchRecord& rec) :
    wxEvent(winid,eventType),
    rec(rec)
{

}

ResultPostedEvent::ResultPostedEvent(const ResultPostedEvent& evt)
{

}

wxEvent* ResultPostedEvent::Clone() const
{
    return new ResultPostedEvent(*this);
}

URLSearchRecord ResultPostedEvent::getRec()
{
    return rec;
}
