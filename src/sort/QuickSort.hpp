#pragma once

#include <vector>

namespace quicksortns
{
template <typename T>
void sort(std::vector<T>& v, int start, int end)
{
    if (start < end)
    {
        int left = start;
        int right = end;
        T pivot = v[(start + end) / 2];
        do
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
            if (start < right) sort(v, start, right);
            if (left < end) sort(v, left, end);
        } while (left <= right);
    }
}
} // namespace quicksortns

template <typename T>
void quicksort(std::vector<T>& v)
{
    quicksortns::sort(v, 0, static_cast<int>(v.size() - 1));
}
