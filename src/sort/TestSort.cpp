#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include "Utils.hpp"
#include "sort/BubbleSort.hpp"
#include "sort/InsertionSort.hpp"
#include "sort/MergeSort.hpp"
#include "sort/QuickSort.hpp"
#include "sort/QuickSort2.hpp"

namespace testing
{
struct SortParam
{
    std::vector<int> v;
    std::string expected;
};

class TestSort : public TestWithParam<SortParam>
{
};

TEST_P(TestSort, bubblesort)
{
    auto v{GetParam().v};
    bubblesort(v);
    ASSERT_THAT(to_string(v), Eq(GetParam().expected));
}

TEST_P(TestSort, insertionsort)
{
    auto v{GetParam().v};
    insertionsort(v);
    ASSERT_THAT(to_string(v), Eq(GetParam().expected));
}

TEST_P(TestSort, mergesort)
{
    auto v{GetParam().v};
    mergesort(v);
    ASSERT_THAT(to_string(v), Eq(GetParam().expected));
}

TEST_P(TestSort, quicksort)
{
    auto v{GetParam().v};
    quicksort(v);
    ASSERT_THAT(to_string(v), Eq(GetParam().expected));
}

TEST_P(TestSort, quicksort2)
{
    auto v{GetParam().v};
    quicksort2(v);
    ASSERT_THAT(to_string(v), Eq(GetParam().expected));
}

INSTANTIATE_TEST_SUITE_P(
    SortTests,
    TestSort,
    Values(
        SortParam{.v = {}, .expected = ""},
        SortParam{.v = {1}, .expected = "1"},
        SortParam{.v = {2, 1}, .expected = "1,2"},
        SortParam{.v = {3, 2, 1}, .expected = "1,2,3"},
        SortParam{.v = {1, 1, 1, 1}, .expected = "1,1,1,1"},
        SortParam{.v = {1, 2, 1, 1, 1}, .expected = "1,1,1,1,2"}));
} // namespace testing
