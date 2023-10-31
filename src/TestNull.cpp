#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace testing
{
TEST(TestNull, testNull)
{
    int* p = static_cast<int*>((void*)0);
    ASSERT_THAT(p, Eq((void*)0));
}
} // namespace testing
