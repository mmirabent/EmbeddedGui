#ifndef URLTHREAD_H
#define URLTHREAD_H

#include <wx/thread.h>
#include <string>
#include <vector>
#include <wx/url.h>


class URLThread : public wxThread
{
    public:
        URLThread(const std::vector<wxURL>& urls, const std::vector<std::string>& terms, std::string** out);
        virtual ~URLThread();

    protected:
        virtual ExitCode Entry();

    private:
        int countSubstringsInString(const std::string& sub, const std::string& str);
        std::string** output;
        std::vector<wxURL> urls;
        std::vector<std::string> terms;
};

#endif // URLTHREAD_H
