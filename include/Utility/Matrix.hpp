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
    void Set(const unsigned int x, const unsigned int y, T& ref);
    void Set(const unsigned int i, T& ref);

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

template <class T>
void Matrix<T>::Set(const unsigned int pX, const unsigned int pY, T& pRef)
{
    elements[pX + (pY * this->rows)] = pRef;
}

template <class T>
void Matrix<T>::Set(const unsigned int pI, T& pRef)
{
    elements[pI] = pRef;
}

} // namespace tomengine

#endif