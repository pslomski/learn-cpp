#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>

namespace testing
{
std::unique_ptr<int> build_up_int(int i)
{
    return std::unique_ptr<int>{new int{i}};
}

TEST(UniquePtr, testUniquePtr)
{
    std::unique_ptr<int> p{build_up_int(1)};
    ASSERT_TRUE(*p == 1);
    std::unique_ptr<int> p2 = std::move(p);
    ++*p2;
    (*p2)++;
    ASSERT_TRUE(*p2 == 3);
}

std::unique_ptr<int> f(std::unique_ptr<int> p)
{
    ++*p;
    return p;
}
void f2(const std::unique_ptr<int>& p)
{
    ++*p;
}

TEST(UniquePtr, testUniquePtr2)
{
    std::unique_ptr<int> p{new int{7}};
    // p = f(p); // error: no copy ctor
    p = f(move(p));
    f2(p);
    ASSERT_TRUE(*p == 9);
}

int* get_int(int i)
{
    int* p = static_cast<int*>(malloc(sizeof(int)));
    *p = i;
    return p;
}

using PtoCF = void (*)(void*);

TEST(UniquePtr, testUniquePtrWithDeleter)
{
    std::unique_ptr<int, PtoCF> p{get_int(1), free};
    ASSERT_TRUE(*p == 1);
}

template <typename T, typename... Args>
std::unique_ptr<T> my_make_unique(Args&&... args)
{
    return std::unique_ptr<T>{new T{args...}};
}

TEST(UniquePtr, testMyMakeUnique)
{
    std::unique_ptr<int> p = my_make_unique<int>(1);
    ASSERT_TRUE(*p == 1);
}
} // namespace testing
