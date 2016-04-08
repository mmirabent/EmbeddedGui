#ifndef URLTHREAD_H
#define URLTHREAD_H

#include <string>
#include <vector>

#include <wx/msgqueue.h>
#include <wx/thread.h>
#include <wx/event.h>
#include <wx/url.h>

#include "URLSearchRecord.h"



class URLThread : public wxThread
{
    public:
        URLThread(const std::vector<std::string>& terms,
                  wxMessageQueue<wxURL>* urls,
                  wxMessageQueue<URLSearchRecord>* results_mq,
                  wxEvtHandler* handler = nullptr);
        virtual ~URLThread();
    protected:
        virtual ExitCode Entry();

    private:
        int countSubstringsInString(const std::string& sub,
                                    const std::string& str);
        std::string** output;
        std::vector<std::string> terms;
        wxMessageQueue<wxURL>* urls;
        wxMessageQueue<URLSearchRecord>* results_mq;
        wxEvtHandler* handler;
};

#endif // URLTHREAD_H
