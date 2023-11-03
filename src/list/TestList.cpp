#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "List.hpp"

namespace testing
{
TEST(List, testConstrucor)
{
    List<int> l;
    ASSERT_TRUE(l.is_empty());
    ASSERT_THAT(l.size(), Eq(0));
}

TEST(List, testInitializerList)
{
    List<int> l{1, 2, 3};
    ASSERT_THAT(l.size(), Eq(3));
}

TEST(List, testCopyConstructor)
{
    List<int> l{1, 2, 3};
    List<int> l2{l};
    ASSERT_THAT(l.size(), Eq(3));
    ASSERT_THAT(l2.size(), Eq(3));
}

TEST(List, testMoveConstructorOnRvalue)
{
    List<int> l2{std::move(List<int>({1, 2, 3}))};
    ASSERT_THAT(l2.size(), Eq(3));
}

TEST(List, testMoveConstructorOnLvalue)
{
    List<int> l{1, 2, 3};
    ASSERT_THAT(l.size(), Eq(3));
    List<int> l2{std::move(l)};
    ASSERT_THAT(l.size(), Eq(0));
    ASSERT_THAT(l2.size(), Eq(3));
}

List<int> return_list()
{
    return List<int>{1, 2, 3};
}

TEST(List, testMoveConstructorOnReturnValue)
{
    List<int> l2{std::move(return_list())};
    ASSERT_THAT(l2.size(), Eq(3));
}

TEST(List, testAdd)
{
    List<int> l;
    l.push_back(1);
    ASSERT_FALSE(l.is_empty());
    ASSERT_THAT(l.size(), Eq(1));
}

TEST(List, testAddTwoElems)
{
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    ASSERT_FALSE(l.is_empty());
    ASSERT_THAT(l.size(), Eq(2));
}

TEST(List, testClear)
{
    List<int> l;
    l.push_back(1);
    l.clear();
    ASSERT_TRUE(l.is_empty());
    ASSERT_THAT(l.size(), Eq(0));
}

TEST(List, testReverseEmpty)
{
    List<int> l;
    l.reverse();
    ASSERT_THAT(l.size(), Eq(0));
}

TEST(List, testReverseOneElem)
{
    List<int> l{1};
    l.reverse();
    ASSERT_THAT(l.size(), Eq(1));
    ASSERT_THAT(l[0], Eq(1));
}

TEST(List, testReverseTwoElems)
{
    List<int> l{1, 2};
    l.reverse();
    ASSERT_THAT(l.size(), Eq(2));
    ASSERT_THAT(l[0], Eq(2));
    ASSERT_THAT(l[1], Eq(1));
}

TEST(List, testReverseFourElems)
{
    List<int> l{1, 2, 3, 4};
    l.reverse();
    ASSERT_THAT(l.size(), Eq(4));
    ASSERT_THAT(l[0], Eq(4));
    ASSERT_THAT(l[1], Eq(3));
    ASSERT_THAT(l[2], Eq(2));
    ASSERT_THAT(l[3], Eq(1));
}
} // namespace testing
