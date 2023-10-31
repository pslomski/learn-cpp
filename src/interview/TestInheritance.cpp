#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Inheritance.hpp"

namespace testing
{
TEST(Interview, testInheritance)
{
    using PtrBase = std::unique_ptr<Base>;
    PtrBase p{new Derived};
    p.get()->fun();
    Derived d;
    ASSERT_THAT(run(d.engine.get()), Eq("GasEngine::start"));
}
} // namespace testing
