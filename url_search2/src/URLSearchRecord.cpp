#include "URLSearchRecord.h"

#include <sstream>

URLSearchRecord::URLSearchRecord()
{

}

URLSearchRecord::URLSearchRecord(wxURL url) : url(url)
{
    //ctor
}

URLSearchRecord::~URLSearchRecord()
{
    //dtor
}

void URLSearchRecord::addSearchResult(std::string term, int n)
{
    results[term] = n;
}

std::string URLSearchRecord::toString()
{
    std::stringstream stream;
    stream << "\nSite: " << url.GetServer().ToStdString() << url.GetPath().ToStdString() << '\n';

    for(auto& kv : results) {
            stream << kv.first << ": " << kv.second << '\n';
    }

    return stream.str();
}
