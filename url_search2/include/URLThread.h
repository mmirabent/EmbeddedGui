#ifndef URLTHREAD_H
#define URLTHREAD_H

#include <wx/thread.h>
#include <string>
#include <vector>
#include <wx/url.h>
#include <wx/msgqueue.h>
#include "URLSearchRecord.h"


class URLThread : public wxThread
{
    public:
        URLThread(const std::vector<std::string>& terms,
                  wxMessageQueue<wxURL>* urls,
                  wxMessageQueue<URLSearchRecord>* results_mq);
        virtual ~URLThread();
        bool isIdle();

    protected:
        virtual ExitCode Entry();

    private:
        int countSubstringsInString(const std::string& sub,
                                    const std::string& str);
        std::string** output;
        std::vector<std::string> terms;
        wxMessageQueue<wxURL>* urls;
        wxMessageQueue<URLSearchRecord>* results_mq;
        bool idle;
};

#endif // URLTHREAD_H
