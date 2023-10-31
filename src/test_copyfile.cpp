#include <catch.hpp>
#include <fstream>

using namespace std;

TEST_CASE("copy")
{
	ifstream is("file.in", ios::binary);
	ofstream os("file.out", ios::binary);
	os << is.rdbuf();
}
