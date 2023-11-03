#pragma once

#include <sstream>

template <class T>
std::string to_string(const T& c)
{
    std::stringstream ss;
    for (auto x : c)
    {
        ss << x << ",";
    }
    std::string s{ss.str()};
    if (!s.empty())
    {
        s.pop_back();
    }
    return s;
}
