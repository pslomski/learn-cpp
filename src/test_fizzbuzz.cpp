#include <catch.hpp>

std::string fizzbuzz(int i)
{
	std::string res;
	if (i % 3 == 0)
		res += "fizz";
	if (i % 5 == 0)
		res += "buzz";
	return res;
}

TEST_CASE("fizzbuzz")
{
	REQUIRE(fizzbuzz(1) == "");
	REQUIRE(fizzbuzz(2) == "");
	REQUIRE(fizzbuzz(3) == "fizz");
	REQUIRE(fizzbuzz(4) == "");
	REQUIRE(fizzbuzz(5) == "buzz");
	REQUIRE(fizzbuzz(6) == "fizz");
	REQUIRE(fizzbuzz(7) == "");
	REQUIRE(fizzbuzz(8) == "");
	REQUIRE(fizzbuzz(9) == "fizz");
	REQUIRE(fizzbuzz(10) == "buzz");
	REQUIRE(fizzbuzz(11) == "");
	REQUIRE(fizzbuzz(12) == "fizz");
	REQUIRE(fizzbuzz(13) == "");
	REQUIRE(fizzbuzz(14) == "");
	REQUIRE(fizzbuzz(15) == "fizzbuzz");
	REQUIRE(fizzbuzz(16) == "");
}