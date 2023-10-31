#include <catch.hpp>
#include <memory>

using namespace std;

unique_ptr<int> build_up_int(int i)
{
	return unique_ptr<int> {new int{ i }};
}

TEST_CASE("unique_ptr")
{
	unique_ptr<int> p{ build_up_int(1) };
	REQUIRE(*p == 1);
	unique_ptr<int> p2 = move(p);
	++*p2;
	(*p2)++;
	REQUIRE(*p2 == 3);
}

unique_ptr<int> f(unique_ptr<int> p)
{
	++*p;
	return p;
}
void f2(const unique_ptr<int>& p)
{
	++*p;
}

TEST_CASE("unique_ptr 2")
{
	unique_ptr<int> p{ new int{7} };
	// p = f(p); // b³¹d: brak konstruktora kopiuj¹cego
	p = f(move(p)); // przekazuje w³asnoœæ w tê i z powrotem
	f2(p); // przekazuje referencjê
	REQUIRE(*p == 9);
}

// pobiera dane z fragmentu programu w jêzyku C
int* get_int(int i)
{
	int* p = static_cast<int*>(malloc(sizeof(int)));
	*p = i;
	return p;
}

using PtoCF = void(*)(void*);

TEST_CASE("unique_ptr with deleter")
{
	unique_ptr<int, PtoCF> p{ get_int(1), free };
	REQUIRE(*p == 1);
}

template<typename T, typename... Args>
unique_ptr<T> my_make_unique(Args&&... args) // domyœlna wersja z usuwaczem
{
	return unique_ptr<T>{new T{ args... }};
}

TEST_CASE("my_make_unique")
{
	unique_ptr<int> p = my_make_unique<int>(1);
	REQUIRE(*p == 1);
}
