#pragma once

#include <vector>

template <class T>
void bubblesort(std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        for (size_t j = 0; j < v.size() - i - 1; ++j)
        {
            if (v[j] > v[j + 1]) std::swap(v[j], v[j + 1]);
        }
    }
}
