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
    T& Get(const unsigned int x, const unsigned int y);
    T& Get(const unsigned int i);

private:
    std::vector<T> elements;
    const unsigned int columns;
    const unsigned int rows;
};

template <class T>
Matrix<T>::Matrix(const unsigned int pColumns, const unsigned int pRows) :
    columns(pColumns), rows(pRows)
{
    this->elements = std::vector<T>(pColumns * pRows);
}

template <class T>
T& Matrix<T>::Get(const unsigned int pX, const unsigned int pY)
{
    return elements[pX + (pY * this->rows)];
}

template <class T>
T& Matrix<T>::Get(const unsigned int pI)
{
    return elements[pI];
}

} // namespace tomengine

#endif