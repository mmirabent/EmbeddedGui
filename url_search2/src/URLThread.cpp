
#include "URLThread.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <wx/sstream.h>


URLThread::URLThread(const std::vector<wxURL>& urls, const std::vector<std::string>& terms, std::string** out) :
    output(out),
    terms(terms),
    urls(urls)
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

    while((pos = str.find(sub,pos)) != std::string::npos) {
        pos += sub.length();
        hit_count++;
    }

    return hit_count;
}

wxThread::ExitCode URLThread::Entry()
{
    std::stringstream str_stream;

    for(wxURL& url : urls) {

        // Actually perform the get request and load the response into get
        wxInputStream* stream = url.GetInputStream();

        if(url.GetError() == wxURL_NOERR) {

            str_stream << wxT("Site: ") << url.GetServer() << url.GetPath() << wxT("\n");

            wxString body;            wxStringOutputStream out_stream(&body);
            stream->Read(out_stream);

            std::cout << url.GetServer().ToStdString() << "\n" << body.ToStdString() << "\n";

            for(std::string& term : terms) {
                std::transform(term.begin(), term.end(), term.begin(), ::tolower);
                str_stream << term << wxT(": ") << countSubstringsInString(term,body.Lower().ToStdString()) << wxT("\n");
            }

            str_stream << wxT("\n");
        }
        delete stream;
    }

    *output = new std::string(str_stream.str());
}
