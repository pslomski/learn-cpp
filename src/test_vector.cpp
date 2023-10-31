#include <catch.hpp>
#include <vector>

TEST_CASE("VectorInt")
{
	using VectorInt = std::vector<int>;
	int i1{ 0 };
	VectorInt::reference i2{ i1 };
	REQUIRE(i1 == i2);
}
