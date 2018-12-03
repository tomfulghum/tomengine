#ifndef TOMENGINE_UTILITY_MATRIX_HPP
#define TOMENGINE_UTILITY_MATRIX_HPP

#include <vector>

namespace tomengine
{

template <class T>
class Matrix
{
public:
    Matrix(const unsigned int columns, const unsigned int rows);

    const unsigned int Columns() const { return this->columns; }
    const unsigned int Rows() const { return this->rows; }
    T& Get(const unsigned int x, const unsigned int y) const;

private:
    std::vector<T> elements;
    const unsigned int columns;
    const unsigned int rows;

    int ConvertIndex(const int x, const int y);
};

template <class T>
Matrix<T>::Matrix(const unsigned int pColumns, const unsigned int pRows) :
    columns(pColumns), rows(pRows)
{
    this->elements = std::vector<T>(pColumns * pRows);
}

template <class T>
T& Matrix<T>::Get(const unsigned int pX, const unsigned int pY) const
{
    return elements[pX + (pY * this->rows)];
}

} // namespace tomengine

#endif