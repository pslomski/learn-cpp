#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

namespace testing
{
TEST(TestToString, testToString)
{
    ASSERT_THAT(std::to_string(static_cast<int>(10)), Eq("10"));
    ASSERT_THAT(std::to_string(static_cast<long>(10)), Eq("10"));
    ASSERT_THAT(std::to_string(static_cast<long long>(10)), Eq("10"));
    ASSERT_THAT(std::to_string(static_cast<unsigned>(10)), Eq("10"));
    ASSERT_THAT(std::to_string(static_cast<unsigned long>(10)), Eq("10"));
    ASSERT_THAT(std::to_string(static_cast<unsigned long long>(10)), Eq("10"));
    ASSERT_THAT(std::to_string(static_cast<float>(10)), Eq("10.000000"));
    ASSERT_THAT(std::to_string(static_cast<double>(10)), Eq("10.000000"));
    ASSERT_THAT(std::to_string(static_cast<long double>(10)), Eq("10.000000"));
}
} // namespace testing
