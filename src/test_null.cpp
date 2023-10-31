#include <catch.hpp>

TEST_CASE("NULL as (void*)0")
{
	int* p = static_cast<int*>((void*)0);
	REQUIRE(p == (void*)0);
}