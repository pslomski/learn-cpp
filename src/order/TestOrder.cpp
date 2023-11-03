#include <array>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <initializer_list>

template <typename T>
bool cmp(const T x, const T y)
{
    return x < y;
}

template <typename T>
class Obj
{
public:
    Obj(const int a1) { a[0] = a1; }
    bool operator<(const Obj& r) const { return a[0] < r.a[0]; }

private:
    std::array<int, 1> a;
};

namespace testing
{

TEST(Order, przeciwzwrotnosc)
{
    ASSERT_FALSE(cmp(0, 0));
}

TEST(Order, przeciwsymetria)
{
    ASSERT_EQ(cmp(1, 2), !cmp(2, 1));
}

TEST(Order, przechodnosc)
{
    ASSERT_TRUE(cmp(1, 2));
    ASSERT_TRUE(cmp(2, 3));
    ASSERT_TRUE(cmp(1, 3));
}

TEST(Order, przechodnoscEkwiwalencji)
{
    ASSERT_TRUE(!(cmp(1, 1) || cmp(1, 1)));
    ASSERT_FALSE(!(cmp(1, 2) || cmp(2, 1)));
}

TEST(Order, objEquivalence)
{
    Obj<int> o{1};
    ASSERT_TRUE(!(cmp(o, o) || cmp(o, o)));
}
} // namespace testing
