#include <gmock/gmock.h>
#include <gtest/gtest.h>

std::string fizzbuzz(int i)
{
    std::string res;
    if (i % 3 == 0) res += "fizz";
    if (i % 5 == 0) res += "buzz";
    return res;
}

namespace testing
{
TEST(Fizzbuzz, fizzbuzz)
{
    ASSERT_THAT(fizzbuzz(1), Eq(""));
    ASSERT_THAT(fizzbuzz(2), Eq(""));
    ASSERT_THAT(fizzbuzz(3), Eq("fizz"));
    ASSERT_THAT(fizzbuzz(4), Eq(""));
    ASSERT_THAT(fizzbuzz(5), Eq("buzz"));
    ASSERT_THAT(fizzbuzz(6), Eq("fizz"));
    ASSERT_THAT(fizzbuzz(7), Eq(""));
    ASSERT_THAT(fizzbuzz(8), Eq(""));
    ASSERT_THAT(fizzbuzz(9), Eq("fizz"));
    ASSERT_THAT(fizzbuzz(10), Eq("buzz"));
    ASSERT_THAT(fizzbuzz(11), Eq(""));
    ASSERT_THAT(fizzbuzz(12), Eq("fizz"));
    ASSERT_THAT(fizzbuzz(13), Eq(""));
    ASSERT_THAT(fizzbuzz(14), Eq(""));
    ASSERT_THAT(fizzbuzz(15), Eq("fizzbuzz"));
    ASSERT_THAT(fizzbuzz(16), Eq(""));
}
} // namespace testing
