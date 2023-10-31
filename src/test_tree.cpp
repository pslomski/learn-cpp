#include <catch.hpp>
#include <sstream>
#include "tree.hpp"

using namespace std;

TEST_CASE("Tree::Tree")
{
	Tree<int> t;
	REQUIRE(t.is_empty() == true);
	REQUIRE(t.size() == 0);
}

TEST_CASE("Tree::insert")
{
	Tree<int> t;
	t.insert(1);
	t.insert(2);	
	t.insert(3);
	t.insert(3);
	REQUIRE(t.is_empty() == false);
	REQUIRE(t.size() == 3);
}

TEST_CASE("Tree::clear")
{
	Tree<int> t;
	for (int i=0; i < 10; ++i)
	 t.insert(i);
	REQUIRE(t.is_empty() == false);
	REQUIRE(t.size() == 10);
	t.clear();
	REQUIRE(t.is_empty() == true);
	REQUIRE(t.size() == 0);
}

TEST_CASE("Tree::traverse_preorder")
{
	Tree<int> t;
	t.insert(5);
	t.insert(1);
	t.insert(4);
	t.insert(3);
	t.insert(2);
	std::stringstream s;
	t.traverse_preorder([&s](const int& val) {s << val; });
	REQUIRE(s.str() == "51432");
}

TEST_CASE("Tree::traverse_inorder")
{
	Tree<int> t;
	t.insert(5);
	t.insert(1);
	t.insert(4);
	t.insert(3);
	t.insert(2);
	std::stringstream s;
	t.traverse_inorder([&s](const int& val) {s << val; });
	REQUIRE(s.str() == "12345");
}

TEST_CASE("Tree::traverse_postorder")
{
	Tree<int> t;
	t.insert(5);
	t.insert(1);
	t.insert(4);
	t.insert(3);
	t.insert(2);
	std::stringstream s;
	t.traverse_postorder([&s](const int& val) {s << val; });
	REQUIRE(s.str() == "23415");
}