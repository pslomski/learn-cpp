#pragma once

#include <vector>

template <class T>
void insertionsort(std::vector<T>& v)
{
    for (size_t i = 1; i < v.size(); ++i)
    {
        for (size_t j = i; j > 0; --j)
        {
            if (v[j] < v[j - 1]) std::swap(v[j], v[j - 1]);
        }
    }
}
