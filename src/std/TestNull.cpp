#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace testing
{
TEST(TestNull, testNull)
{
    ASSERT_THAT((void*)0, Eq(nullptr));
}
} // namespace testing
