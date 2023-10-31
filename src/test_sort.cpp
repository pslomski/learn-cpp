#include <catch.hpp>
#include <vector>
#include "utils.hpp"

using namespace ps;

template<class T>
void bubblesort(std::vector<T>& v)
{
	for (size_t i = 0; i < v.size(); ++i) {
		for (size_t j = 0; j < v.size() - i - 1; ++j) {
			if (v[j] > v[j + 1])
				std::swap(v[j], v[j + 1]);
		}
	}
}

TEST_CASE("bubblesort 0")
{
	std::vector<int> v;
	bubblesort(v);
	REQUIRE(to_string(v) == "");
}

TEST_CASE("bubblesort 1")
{
	std::vector<int> v{ 1 };
	bubblesort(v);
	REQUIRE(to_string(v) == "1");
}

TEST_CASE("bubblesort 2")
{
	std::vector<int> v{ 2, 1 };
	bubblesort(v);
	REQUIRE(to_string(v) == "1,2");
}

TEST_CASE("bubblesort 4")
{
	std::vector<int> v{ 4,2,3,1 };
	bubblesort(v);
	REQUIRE(to_string(v) == "1,2,3,4");
}

TEST_CASE("bubblesort 8")
{
	std::vector<int> v{ 12,18,42,44,55,67,94,6 };
	bubblesort(v);
	REQUIRE(to_string(v) == "6,12,18,42,44,55,67,94");
}

template<class T>
void insertionsort(std::vector<T>& v)
{
	for (size_t i = 1; i < v.size(); ++i) {
		for (size_t j = i; j > 0; --j) {
			if (v[j] < v[j - 1])
				std::swap(v[j], v[j - 1]);
		}
	}
}

TEST_CASE("insertionsort 0")
{
	std::vector<int> v;
	insertionsort(v);
	REQUIRE(to_string(v) == "");
}

TEST_CASE("insertionsort 1")
{
	std::vector<int> v{ 1 };
	insertionsort(v);
	REQUIRE(to_string(v) == "1");
}

TEST_CASE("insertionsort 2")
{
	std::vector<int> v{ 2, 1 };
	insertionsort(v);
	REQUIRE(to_string(v) == "1,2");
}

TEST_CASE("insertionsort 4")
{
	std::vector<int> v{ 4,2,3,1 };
	insertionsort(v);
	REQUIRE(to_string(v) == "1,2,3,4");
}