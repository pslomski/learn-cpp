#include <catch.hpp>
#include "quicksort.hpp"
#include "utils.hpp"

using namespace ps;

TEST_CASE("quicksort 0")
{
	std::vector<int> v;
	quicksort(v);
	REQUIRE(to_string(v) == "");
}

TEST_CASE("quicksort 1")
{
	std::vector<int> v{ 1 };
	quicksort(v);
	REQUIRE(to_string(v) == "1");
}

TEST_CASE("quicksort 2")
{
	std::vector<int> v{ 2, 1 };
	quicksort(v);
	REQUIRE(to_string(v) == "1,2");
}

TEST_CASE("quicksort 4")
{
	std::vector<int> v{ 4,2,3,1 };
	quicksort(v);
	REQUIRE(to_string(v) == "1,2,3,4");
}

TEST_CASE("quicksort 8")
{
	std::vector<int> v{ 12,18,42,44,55,67,94,6 };
	quicksort(v);
	REQUIRE(to_string(v) == "6,12,18,42,44,55,67,94");
}


TEST_CASE("quicksort 1112111")
{
	std::vector<int> v{ 1,1,1,2,1,1,1 };
	quicksort(v);
	REQUIRE(to_string(v) == "1,1,1,1,1,1,2");
}

TEST_CASE("quicksort 139")
{
	std::vector<int> v{ 1,3,9,7,8,3,2 };
	quicksort(v);
	REQUIRE(to_string(v) == "1,2,3,3,7,8,9");
}