#include <catch.hpp>
#include <array>
#include <initializer_list>

template<typename T>
bool cmp(T x, T y)
{
	return x < y;
}

TEST_CASE("przeciwzwrotnosc")
{
	REQUIRE(cmp(0, 0) == false);
}

TEST_CASE("przeciwsymetria")
{
	REQUIRE(cmp(1, 2) == !cmp(2, 1));
}

TEST_CASE("przechodnosc")
{
	REQUIRE(cmp(1, 2) == true);
	REQUIRE(cmp(2, 3) == true);
	REQUIRE(cmp(1, 3) == true);
}

TEST_CASE("przechodnosc ekwiwalencji")
{
	REQUIRE(!(cmp(1, 1) || cmp(1, 1)) == true);
	REQUIRE(!(cmp(1, 2) || cmp(2, 1)) == false);
}

template<typename T>
class Obj {
public:
	Obj(int a1)
	{
		a[0] = a1;
	}
	bool operator<(const Obj& r) const
	{
		return a[0] < r.a[0];
	}
private:
	std::array<int, 1> a;
};

TEST_CASE("Obj equivalence")
{
	Obj<int> o{ 1 };
	REQUIRE(!(cmp(o, o) || cmp(o, o)) == true);
}