#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <sstream>
#include "Tree.hpp"

namespace testing
{
TEST(Tree, ctor)
{
    Tree<int> t;
    ASSERT_TRUE(t.is_empty());
    ASSERT_TRUE(t.size() == 0);
}

TEST(Tree, insert)
{
    Tree<int> t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(3);
    ASSERT_FALSE(t.is_empty());
    ASSERT_TRUE(t.size() == 3);
}

TEST(Tree, clear)
{
    Tree<int> t;
    for (int i = 0; i < 10; ++i)
        t.insert(i);
    ASSERT_FALSE(t.is_empty());
    ASSERT_TRUE(t.size() == 10);
    t.clear();
    ASSERT_TRUE(t.is_empty());
    ASSERT_TRUE(t.size() == 0);
}

TEST(Tree, traverse_preorder)
{
    Tree<int> t;
    t.insert(5);
    t.insert(1);
    t.insert(4);
    t.insert(3);
    t.insert(2);
    std::stringstream s;
    t.traverse_preorder([&s](const int& val) { s << val; });
    ASSERT_TRUE(s.str() == "51432");
}

TEST(Tree, traverse_inorder)
{
    Tree<int> t;
    t.insert(5);
    t.insert(1);
    t.insert(4);
    t.insert(3);
    t.insert(2);
    std::stringstream s;
    t.traverse_inorder([&s](const int& val) { s << val; });
    ASSERT_TRUE(s.str() == "12345");
}

TEST(Tree, traverse_postorder)
{
    Tree<int> t;
    t.insert(5);
    t.insert(1);
    t.insert(4);
    t.insert(3);
    t.insert(2);
    std::stringstream s;
    t.traverse_postorder([&s](const int& val) { s << val; });
    ASSERT_TRUE(s.str() == "23415");
}
} // namespace testing
