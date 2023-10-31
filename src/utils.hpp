#pragma once

#ifndef UTILS_H_INCLUDED
#define  UTILS_H_INCLUDED

#include <sstream>

#define NAMESPACE_PS_START namespace ps {
#define NAMESPACE_PS_END }

NAMESPACE_PS_START

template<class T>
std::string to_string(const T& c)
{
	std::stringstream ss;
	for (auto x : c)
		ss << x << ",";
	std::string s{ ss.str() };
	if (!s.empty())
		s.pop_back();
	return s;
}

NAMESPACE_PS_END

#endif // UTILS_H_INCLUDED
