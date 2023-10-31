#pragma once

#ifndef QUICKSORT_H_INCLUDED
#define  QUICKSORT_H_INCLUDED

#include <vector>
#include "utils.hpp"

NAMESPACE_PS_START

template<typename T>
static void sort(std::vector<T>& v, int start, int end)
{
	if (start < end) {
		int left = start;
		int right = end;
		T pivot = v[(start + end) / 2];
		do {
			while (v[left] < pivot)
				++left;
			while (v[right] > pivot)
				--right;
			if (left <= right) {
				std::swap(v[left], v[right]);
				++left;
				--right;
			}
			if (start < right)
				sort(v, start, right);
			if (left < end)
				sort(v, left, end);
		} while (left <= right);
	}
}

template<typename T>
void quicksort(std::vector<T>& v)
{
	sort(v, 0, static_cast<int>(v.size() - 1));
}

NAMESPACE_PS_END

#endif // QUICKSORT_H_INCLUDED