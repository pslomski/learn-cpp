#pragma once

#include <vector>

namespace mergesortns
{
template <typename T>
void merge(std::vector<T>& v, int start, int mid, int end)
{
    std::vector<T> tmp(end - start + 1);
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (v[i] <= v[j])
        {
            tmp[k] = v[i];
            ++i;
        }
        else
        {
            tmp[k] = v[j];
            ++j;
        }
        ++k;
    }
    while (i <= mid)
    {
        tmp[k] = v[i];
        ++k;
        ++i;
    }
    while (j <= end)
    {
        tmp[k] = v[j];
        ++k;
        ++j;
    }
    for (i = start; i <= end; ++i)
    {
        v[i] = tmp[i - start];
    }
}

template <typename T>
void sort(std::vector<T>& v, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        sort(v, start, mid);
        sort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}
} // namespace mergesortns

template <typename T>
void mergesort(std::vector<T>& v)
{
    mergesortns::sort(v, 0, static_cast<int>(v.size() - 1));
}
