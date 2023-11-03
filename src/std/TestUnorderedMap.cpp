#include <functional>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

namespace testing
{
TEST(UnorderedMap, hashInt)
{
    std::hash<int> h;
    ASSERT_THAT(h(1), Eq(1));
}

TEST(UnorderedMap, unordered_map)
{
    std::unordered_multimap<std::string, int> m;
    m.insert({"apple", 1});
    m.insert({"apple", 2});
    auto pp = m.equal_range("apple");
    ASSERT_THAT(pp.first, Ne(pp.second));
    auto p = pp.first;
    ASSERT_THAT(p->second, Eq(1));
    ++p;
    ASSERT_THAT(p->second, Eq(2));
}
} // namespace testing
