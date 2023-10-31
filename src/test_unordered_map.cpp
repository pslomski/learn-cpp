#include <catch.hpp>
#include <unordered_map>

using namespace std;

TEST_CASE("hash<int>")
{
	hash<int> h;
	REQUIRE(h(0) == 5558979605539197941);
}

TEST_CASE("unordered_map::1")
{
	unordered_multimap<string, int> m;
	m.insert({ "apple", 1 });
	m.insert({ "apple", 2 });
	auto pp = m.equal_range("apple");
	REQUIRE(pp.first != pp.second);
	auto p = pp.first;
	REQUIRE(p->second == 1);
	++p;
	REQUIRE(p->second == 2);
}