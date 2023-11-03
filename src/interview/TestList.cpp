#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "List.hpp"

namespace testing
{
TEST(Interview, testList)
{
    interview::List<int> l;
    l.add(1);
    l.add(2);
    ASSERT_THAT(l.to_string(), Eq("1,2"));
}
} // namespace testing
