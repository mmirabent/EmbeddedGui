#include "URLThread.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <wx/sstream.h>

wxDECLARE_EVENT(RESULTS_POSTED_EVENT,wxCommandEvent);

URLThread::URLThread(const std::vector<std::string>& terms,
                     wxMessageQueue<wxURL>* urls,
                     wxMessageQueue<URLSearchRecord>* results_mq,
                     wxEvtHandler* handler) :
    terms(terms),
    urls(urls),
    results_mq(results_mq),
    handler(handler)
{

}

URLThread::~URLThread()
{
    //dtor
}

int URLThread::countSubstringsInString(const std::string& sub, const std::string& str)
{
    int hit_count;
    size_t pos = 0;

    while((pos = str.find(sub,pos)) != std::string::npos)
    {
        pos += sub.length();
        hit_count++;
    }

    return hit_count;
}

wxThread::ExitCode URLThread::Entry()
{
    std::stringstream str_stream;
    wxURL url;
    wxMessageQueueError error;

    while(!TestDestroy())
    {
        if((error = urls->ReceiveTimeout(5,url)) == wxMSGQUEUE_NO_ERROR)
        {
            URLSearchRecord result(url);
            if(url.GetError() == wxURL_NOERR)
            {
                // Actually perform the get request and load the response into get
                wxInputStream* stream = url.GetInputStream();

                // Trap for young players. GetInputStream can fail and return null.
                // This is not in the docs
                if(stream != nullptr && stream->IsOk())
                {
                    wxString* body = new wxString();
                    wxStringOutputStream out_stream(body);
                    stream->Read(out_stream);

                    for(std::string& term : terms)
                    {
                        std::transform(term.begin(), term.end(), term.begin(), ::tolower);
                        result.addSearchResult(term, countSubstringsInString(term,body->Lower().ToStdString()));
                        handler->QueueEvent(new wxCommandEvent(RESULTS_POSTED_EVENT));
                    }
                    delete body;
                }
                delete stream;

            }
            results_mq->Post(result);
        }
    }

    return (wxThread::ExitCode)0;
}
