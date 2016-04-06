#include "URLThread.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <wx/sstream.h>


URLThread::URLThread(const std::vector<std::string>& terms, wxMessageQueue<wxURL>* urls, wxMessageQueue<URLSearchRecord>* results_mq) :
    terms(terms),
    urls(urls),
    results_mq(results_mq),
    idle(false)
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

    while(true)
    {
        if(urls->ReceiveTimeout(100,url) == wxMSGQUEUE_TIMEOUT)
        {
            idle = true;
            continue;
        }

        idle = false;

        // Actually perform the get request and load the response into get
        wxInputStream* stream = url.GetInputStream();

        if(url.GetError() == wxURL_NOERR)
        {
            // Make the search record object to push onto the message queue later
            URLSearchRecord result(url);

            wxString body;
            wxStringOutputStream out_stream(&body);
            stream->Read(out_stream);

            for(std::string& term : terms)
            {
                std::transform(term.begin(), term.end(), term.begin(), ::tolower);
                result.addSearchResult(term, countSubstringsInString(term,body.Lower().ToStdString()));
            }

            results_mq->Post(result);
        }
        delete stream;
    }

    return (wxThread::ExitCode)0;
}
