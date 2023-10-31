#include <catch.hpp>
#include "list.hpp"

using namespace std;

TEST_CASE("List::List")
{
	List<int> l;
	REQUIRE(l.is_empty() == true);
	REQUIRE(l.size() == 0);
}

TEST_CASE("List::List(initializer list)")
{
	List<int> l{ 1, 2, 3 };
	REQUIRE(l.size() == 3);
}

TEST_CASE("List::List(copy constructor)")
{
	List<int> l{ 1, 2, 3 };
	List<int> l2{ l };
	REQUIRE(l.size() == 3);
	REQUIRE(l2.size() == 3);
}

TEST_CASE("List::List(move constructor on rvalue)")
{
	List<int> l2{ std::move(List<int>({ 1, 2, 3 })) };
	REQUIRE(l2.size() == 3);
}

TEST_CASE("List::List(move constructor on lvalue)")
{
	List<int> l{ 1, 2, 3 };
	List<int> l2{ std::move(l) };
	REQUIRE(l.size() == 0);
	REQUIRE(l2.size() == 3);
}

List<int> return_list()
{
	return List<int> { 1, 2, 3 };
}

TEST_CASE("List::List(move constructor on return value)")
{
	List<int> l2{ move(return_list()) };
	REQUIRE(l2.size() == 3);
}

TEST_CASE("List::add")
{
	List<int> l;
	l.push_back(1);
	REQUIRE(l.is_empty() == false);
	REQUIRE(l.size() == 1);
}

TEST_CASE("List::add two elems")
{
	List<int> l;
	l.push_back(1);
	l.push_back(2);
	REQUIRE(l.is_empty() == false);
	REQUIRE(l.size() == 2);
}

TEST_CASE("List::clear")
{
	List<int> l;
	l.push_back(1);
	l.clear();
	REQUIRE(l.is_empty() == true);
	REQUIRE(l.size() == 0);
}

TEST_CASE("List::reverse empty")
{
	List<int> l;
	l.reverse();
	REQUIRE(l.size() == 0);
}

TEST_CASE("List::reverse 1 elem")
{
	List<int> l{ 1 };
	l.reverse();
	REQUIRE(l.size() == 1);
	REQUIRE(l[0] == 1);
}

TEST_CASE("List::reverse 2 elems")
{
	List<int> l{ 1, 2 };
	l.reverse();
	REQUIRE(l.size() == 2);
	REQUIRE(l[0] == 2);
	REQUIRE(l[1] == 1);
}

TEST_CASE("List::reverse 4 elems")
{
	List<int> l{ 1, 2, 3, 4 };
	l.reverse();
	REQUIRE(l.size() == 4);
	REQUIRE(l[0] == 4);
	REQUIRE(l[1] == 3);
	REQUIRE(l[2] == 2);
	REQUIRE(l[3] == 1);
}
