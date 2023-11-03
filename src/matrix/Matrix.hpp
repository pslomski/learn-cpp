#pragma once

#include <stdexcept>
#include <vector>

class matrix_error : public std::runtime_error
{
public:
    matrix_error(const char* message) : std::runtime_error(message) {}
};

template <class T>
class Matrix
{
public:
    Matrix() { resize(0, 0); }
    Matrix(size_t row_count_, size_t col_count_) { resize(row_count_, col_count_); }
    void resize(size_t row_count_, size_t col_count_)
    {
        row_count = row_count_;
        col_count = col_count_;
        data.resize(row_count * col_count);
    }
    size_t get_row_count() const { return row_count; }
    size_t get_col_count() const { return col_count; }
    void set(size_t row, size_t col, T value) { data[get_index(row, col)] = value; }
    const T get(size_t row, size_t col) const { return data[get_index(row, col)]; }

    static Matrix<T> add(const Matrix<T>& m1, const Matrix<T>& m2)
    {
        if (m1.get_row_count() != m2.get_row_count())
        {
            throw matrix_error("row count mismatch");
        }
        if (m1.get_col_count() != m2.get_col_count())
        {
            throw matrix_error("col count mismatch");
        }

        Matrix<T> res(m1.get_row_count(), m1.get_col_count());
        for (size_t index = 0; index < m1.data.size(); ++index)
        {
            res.data[index] = m1.data[index] + m2.data[index];
        }
        return res;
    }

    static Matrix<T> subtract(const Matrix<T>& m1, const Matrix<T>& m2)
    {
        if (m1.get_row_count() != m2.get_row_count())
        {
            throw matrix_error("row count mismatch");
        }
        if (m1.get_col_count() != m2.get_col_count())
        {
            throw matrix_error("col count mismatch");
        }

        Matrix<T> res(m1.get_row_count(), m1.get_col_count());
        for (size_t index = 0; index < m1.data.size(); ++index)
        {
            res.data[index] = m1.data[index] - m2.data[index];
        }
        return res;
    }

    static Matrix<T> multiplicate(const Matrix<T>& m1, const Matrix<T>& m2)
    {
        if (m1.get_row_count() != m2.get_col_count())
        {
            throw matrix_error("row col count mismatch");
        }

        Matrix<T> res(m1.get_row_count(), m2.get_col_count());
        for (int row = 0; row < res.get_row_count(); ++row)
        {
            for (int col = 0; col < res.get_col_count(); ++col)
            {
                res.set(row, col, mulrowcol(m1, row, m2, col));
            }
        }
        return res;
    }

private:
    std::vector<T> data;
    size_t row_count;
    size_t col_count;
    const size_t get_index(size_t row, size_t col) const { return row * col_count + col; }
    static const T mulrowcol(const Matrix<T>& m1, size_t row, const Matrix<T>& m2, size_t col)
    {
        T res{0};
        for (size_t i = 0; i < m1.get_col_count(); ++i)
        {
            res += m1.get(row, i) * m2.get(i, col);
        }
        return res;
    }
};
