#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Matrix.hpp"

namespace testing
{
TEST(Matrix, testResize)
{
    Matrix<int> m;
    m.resize(2, 3);
    ASSERT_THAT(m.get_row_count(), Eq(2));
    ASSERT_THAT(m.get_col_count(), Eq(3));
}

TEST(Matrix, testGetRowColCount)
{
    Matrix<int> m(2, 3);
    ASSERT_THAT(m.get_row_count(), Eq(2));
    ASSERT_THAT(m.get_col_count(), Eq(3));
}

TEST(Matrix, testSetGet)
{
    Matrix<int> m(2, 3);
    m.set(0, 0, 1);
    ASSERT_THAT(m.get(0, 0), Eq(1));
}

TEST(Matrix, testThrowsMatrixErrorWhenRowMismatch)
{
    Matrix<int> m1(2, 3);
    Matrix<int> m2(4, 5);
    ASSERT_THROW(Matrix<int>::add(m1, m2), matrix_error);
}

TEST(Matrix, testThrowsMatrixErrorWhenColMismatch)
{
    Matrix<int> m1(2, 3);
    Matrix<int> m2(2, 5);
    ASSERT_THROW(Matrix<int>::add(m1, m2), matrix_error);
}

TEST(Matrix, testAdd)
{
    Matrix<int> m1(2, 3);
    Matrix<int> m2(2, 3);
    m1.set(0, 0, 1);
    m2.set(0, 0, 2);
    m1.set(1, 2, -1);
    m2.set(1, 2, 2);
    Matrix<int> expected = Matrix<int>::add(m1, m2);
    ASSERT_THAT(expected.get(0, 0), Eq(3));
    ASSERT_THAT(expected.get(1, 2), Eq(1));
}

TEST(Matrix, testSubtractThrowsMatrixErrorWhenRowMismatch)
{
    Matrix<int> m1(2, 3);
    Matrix<int> m2(4, 5);
    ASSERT_THROW(Matrix<int>::subtract(m1, m2), matrix_error);
}

TEST(Matrix, testSubtractThrowsMatrixErrorWhenColMismatch)
{
    Matrix<int> m1(2, 3);
    Matrix<int> m2(2, 5);
    ASSERT_THROW(Matrix<int>::subtract(m1, m2), matrix_error);
}

TEST(Matrix, testSubtract)
{
    Matrix<int> m1(2, 3);
    Matrix<int> m2(2, 3);
    m1.set(0, 0, 1);
    m2.set(0, 0, 2);
    m1.set(1, 2, -1);
    m2.set(1, 2, 2);
    Matrix<int> expected = Matrix<int>::subtract(m1, m2);
    ASSERT_THAT(expected.get(0, 0), Eq(-1));
    ASSERT_THAT(expected.get(1, 2), Eq(-3));
}

TEST(Matrix, testMultiplicateThrowsMatrixErrorWhenRowColMismatch)
{
    Matrix<int> m1(2, 3);
    Matrix<int> m2(2, 3);
    ASSERT_THROW(Matrix<int>::multiplicate(m1, m2), matrix_error);
}

TEST(Matrix, testMultiplicate)
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
    ASSERT_THAT(expected.get_row_count(), Eq(2));
    ASSERT_THAT(expected.get_col_count(), Eq(2));
    ASSERT_THAT(expected.get(0, 0), Eq(776));
    ASSERT_THAT(expected.get(1, 1), Eq(1472));
}
} // namespace testing
