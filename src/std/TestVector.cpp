#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

namespace testing
{
TEST(Vector, vectorInt)
{
    using VectorInt = std::vector<int>;
    int i1{0};
    VectorInt::reference i2{i1};
    ASSERT_THAT(i1, Eq(i2));
}
} // namespace testing
