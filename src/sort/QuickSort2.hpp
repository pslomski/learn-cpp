#pragma once

#include <vector>

namespace quicksort2ns
{
template <typename T>
int partition_old(std::vector<T>& v, int start, int end)
{
    int left = start;
    int right = end;
    T pivot = v[end];
    while (left <= right)
    {
        while (v[left] < pivot)
            ++left;
        while (v[right] > pivot)
            --right;
        if (left <= right)
        {
            std::swap(v[left], v[right]);
            ++left;
            --right;
        }
    }
    return (left + right) / 2;
}

template <typename T>
int partition(std::vector<T>& v, int start, int end)
{
    T pivot_value = v[end];
    int pivot_index = start;
    for (int i = start; i < end; ++i)
    {
        if (v[i] < pivot_value)
        {
            std::swap(v[i], v[pivot_index]);
            ++pivot_index;
        }
    }
    std::swap(v[end], v[pivot_index]);
    return pivot_index;
}

template <typename T>
void sort(std::vector<T>& v, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(v, start, end);
        sort(v, start, pivot - 1);
        sort(v, pivot + 1, end);
    }
}
} // namespace quicksort2ns

template <typename T>
void quicksort2(std::vector<T>& v)
{
    quicksort2ns::sort(v, 0, static_cast<int>(v.size() - 1));
}
