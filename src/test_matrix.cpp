#include <catch.hpp>
#include "matrix.hpp"

using namespace std;

TEST_CASE("Matrix::resize")
{
	Matrix<int> m;
	m.resize(2, 3);
	REQUIRE(m.get_row_count() == 2);
	REQUIRE(m.get_col_count() == 3);
}

TEST_CASE("Matrix::get_row_count, Matrix::get_col_count")
{
	Matrix<int> m(2, 3);
	REQUIRE(m.get_row_count() == 2);
	REQUIRE(m.get_col_count() == 3);
}

TEST_CASE("Matrix::set, Matrix::get")
{
	Matrix<int> m(2, 3);
	m.set(0, 0, 1);
	REQUIRE(m.get(0, 0) == 1);
}

TEST_CASE("Matrix::add throws matrix_error when row mismatch")
{
	Matrix<int> m1(2, 3);
	Matrix<int> m2(4, 5);
	REQUIRE_THROWS(Matrix<int>::add(m1, m2));
}

TEST_CASE("Matrix::add throws matrix_error when col mismatch")
{
	Matrix<int> m1(2, 3);
	Matrix<int> m2(2, 5);
	REQUIRE_THROWS(Matrix<int>::add(m1, m2));
}

TEST_CASE("Matrix::add")
{
	Matrix<int> m1(2, 3);
	Matrix<int> m2(2, 3);
	m1.set(0, 0, 1);
	m2.set(0, 0, 2);
	m1.set(1, 2, -1);
	m2.set(1, 2, 2);
	Matrix<int> expected = Matrix<int>::add(m1, m2);
	REQUIRE(expected.get(0, 0) == 3);
	REQUIRE(expected.get(1, 2) == 1);
}

TEST_CASE("Matrix::subtract throws matrix_error when row mismatch")
{
	Matrix<int> m1(2, 3);
	Matrix<int> m2(4, 5);
	REQUIRE_THROWS(Matrix<int>::subtract(m1, m2));
}

TEST_CASE("Matrix::subtract throws matrix_error when col mismatch")
{
	Matrix<int> m1(2, 3);
	Matrix<int> m2(2, 5);
	REQUIRE_THROWS(Matrix<int>::subtract(m1, m2));
}

TEST_CASE("Matrix::subtract")
{
	Matrix<int> m1(2, 3);
	Matrix<int> m2(2, 3);
	m1.set(0, 0, 1);
	m2.set(0, 0, 2);
	m1.set(1, 2, -1);
	m2.set(1, 2, 2);
	Matrix<int> expected = Matrix<int>::subtract(m1, m2);
	REQUIRE(expected.get(0, 0) == -1);
	REQUIRE(expected.get(1, 2) == -3);
}

TEST_CASE("Matrix::multiplicate throw when row col mismatch")
{
	Matrix<int> m1(2, 3);
	Matrix<int> m2(2, 3);
	REQUIRE_THROWS(Matrix<int>::multiplicate(m1, m2));
}

TEST_CASE("Matrix::multiplicate")
{
	Matrix<int> m1(2, 3);
	Matrix<int> m2(3, 2);
	m1.set(0, 0, 11);
	m1.set(0, 1, 12);
	m1.set(0, 2, 13);
	m1.set(1, 0, 21);
	m1.set(1, 1, 22);
	m1.set(1, 2, 23);

	m2.set(0, 0, 11);
	m2.set(0, 1, 12);
	m2.set(1, 0, 21);
	m2.set(1, 1, 22);
	m2.set(2, 0, 31);
	m2.set(2, 1, 32);
	Matrix<int> expected = Matrix<int>::multiplicate(m1, m2);
	REQUIRE(expected.get_row_count() == 2);
	REQUIRE(expected.get_col_count() == 2);
	REQUIRE(expected.get(0, 0) == 776);
	REQUIRE(expected.get(1, 1) == 1472);
}
