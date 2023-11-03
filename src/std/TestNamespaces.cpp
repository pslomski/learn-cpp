#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace foo
{
int fooReturn0()
{
    return 0;
}
namespace
{
int fooReturn1()
{
    return 1;
}
} // namespace
} // namespace foo

namespace testing
{
TEST(TestNamespaces, testNamespaces)
{
    ASSERT_THAT(foo::fooReturn0(), Eq(0));
    ASSERT_THAT(foo::fooReturn1(), Eq(1));
}
} // namespace testing
