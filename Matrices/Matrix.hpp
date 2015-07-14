#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../numberbase.h"

template<typename T>
class Matrix : public NumberBase
{
    public:
        Matrix();
        Matrix(unsigned int x, unsigned int y);
        
        Matrix(const Matrix& other);
        
        ~Matrix();
        
        // element accessor
        T& operator ()(unsigned int x, unsigned int y);
        const T& operator ()(unsigned int x, unsigned int y) const;
        
        void resize(unsigned int x, unsigned int y);
        
        unsigned int numCols() const;
        unsigned int numRows() const;
        
        virtual void print();
        virtual void demo();
        
        // convert element type
        template<typename U>
        operator Matrix<U>() const;
		
        void fill();
        
        static bool addOrSubCompatible(const Matrix<T>& lhs, const Matrix<T>& rhs);
        static bool multiplyCompatible(const Matrix<T>& lhs, const Matrix<T>& rhs);
        
    private:
		unsigned int cols;
        unsigned int rows;

        T* data;
};

template<typename T>
Matrix<T> operator +(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if(!Matrix<T>::addOrSubCompatible(lhs, rhs))
    {
        throw std::logic_error("The matrices are of incompatible size.");
    }
    
    const unsigned int cols = lhs.numCols();
    const unsigned int rows = lhs.numRows();
    
    Matrix<T> nm(cols, rows);
    
    for(unsigned int i = 0; i < cols * rows; ++i)
    {
        unsigned int iX = i % cols;
        unsigned int iY = i / cols;
        nm(iX, iY) = lhs(iX, iY) + rhs(iX, iY);
    }
    
    return nm;
}

template<typename T>
Matrix<T> operator -(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if(!Matrix<T>::addOrSubCompatible(lhs, rhs))
    {
        throw std::logic_error("The matrices are of incompatible size.");
    }
    
    const unsigned int cols = lhs.numCols();
    const unsigned int rows = lhs.numRows();
    
    Matrix<T> nm(cols, rows);
    
    for(unsigned int i = 0; i < cols * rows; ++i)
    {
        unsigned int iX = i % cols;
        unsigned int iY = i / cols;
        nm(iX, iY) = lhs(iX, iY) - rhs(iX, iY);
    }
    
    return nm;
}

template<typename T>
Matrix<T> operator *(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    if(!Matrix<T>::multiplyCompatible(lhs, rhs))
    {
        throw std::logic_error("The matrices are of incompatible size.");
    }
    
    const unsigned int cols = rhs.numCols();
    const unsigned int rows = lhs.numRows();
    
    Matrix<T> nm(cols, rows);
    
    const unsigned int sameDim = lhs.numCols();
    
    for(unsigned int i = 0; i < cols * rows; ++i)
    {
        unsigned int iX = i % cols;
        unsigned int iY = i / cols;
        
        T e = 0;
        
        for(unsigned int n = 0; n < sameDim; ++n)
        {
            e += lhs(n, iY) * rhs(iX, n);
        }
        
        nm(iX, iY) = e;
    }
    
    return nm;
}

template<typename T>
Matrix<T> operator *(T lhs, const Matrix<T>& rhs)
{
    const unsigned int cols = rhs.numCols();
    const unsigned int rows = rhs.numRows();
    
    Matrix<T> nm(cols, rows);
    
    for(unsigned int i = 0; i < cols * rows; ++i)
    {
        unsigned int iX = i % cols;
        unsigned int iY = i / cols;
        nm(iX, iY) = rhs(iX, iY) * lhs;
    }
    
    return nm;
}

template<typename T>
Matrix<T> operator *(const Matrix<T>& lhs, T rhs)
{
    return rhs * lhs;
}

template<typename T>
Matrix<T>::Matrix()
:   cols(0),
    rows(0),
    data(NULL)
{}

template<typename T>
Matrix<T>::Matrix(unsigned int x, unsigned int y)
:   cols(x),
    rows(y),
    data(new T[x * y]())
{}

template<typename T>
Matrix<T>::Matrix(const Matrix& other)
:   cols(0),
    rows(0)
{
    resize(other.cols, other.rows);
    
    for(unsigned int i = 0; i < cols * rows; ++i)
    {
        unsigned int iX = i % cols;
        unsigned int iY = i / cols;
        (*this)(iX, iY) = other(iX, iY);
    }
}

template<typename T>
Matrix<T>::~Matrix()
{
    if(data)
    {
        delete[] data;
    }
}

template<typename T>
T& Matrix<T>::operator ()(unsigned int x, unsigned int y)
{
    return data[x + y * cols];
}

template<typename T>
const T& Matrix<T>::operator ()(unsigned int x, unsigned int y) const
{
    return data[x + y * cols];
}

template<typename T>
void Matrix<T>::resize(unsigned int x, unsigned int y)
{
    if(x * y <= cols * rows && x <= cols && y <= rows)
    {
        // if we're going to be smaller, just make it look like it.
        // just in case we expand in size later
        cols = x;
        rows = y;
    }
    else
    {
        cols = x;
        rows = y;
        
        // we're expanding in at least one dimension
        T* newData = new T[cols * rows]();
        
        for(unsigned int i = 0; i < cols * rows; ++i)
            newData[i] = data[i];
        
        delete[] data;
        data = newData;
    }
}

template<typename T>
unsigned int Matrix<T>::numCols() const
{
    return cols;
}

template<typename T>
unsigned int Matrix<T>::numRows() const
{
    return rows;
}

template<typename T>
void Matrix<T>::print()
{
    for(unsigned int i = 0; i < rows; ++i)
    {
        for(unsigned int j = 0; j < cols; ++j)
        {
            std::cout << this->operator()(j, i) << '\t';
        }
        
        std::cout << '\n';
    }
}

template<typename T>
void Matrix<T>::demo()
{
    std::srand(std::time(0));
    
    Matrix<int> m1(3, 3);
    Matrix<int> m2(3, 3);
    
    m1.fill();
    m2.fill();
    
    std::cout << "matrix 1:\n";
    m1.print();
    
    std::cout << "matrix 2:\n";
    m2.print();
    
    Matrix<int> mAdd = m1 + m2;
    Matrix<int> mSub = m1 - m2;
    Matrix<int> mMult = m1 * m2;
    Matrix<int> mScale1 = 3 * m1;
    Matrix<int> mScale2 = m2 * 3;
    
    std::cout << "\nmatrix add:\n";
    mAdd.print();
    
    std::cout << "matrix sub:\n";
    mSub.print();
    
    std::cout << "matrix mult:\n";
    mMult.print();
    
    std::cout << "matrix scale 1:\n";
    mScale1.print();
    
    std::cout << "matrix scale 2:\n";
    mScale2.print();
}

template<typename T>
template<typename U>
Matrix<T>::operator Matrix<U>() const
{
    Matrix<U> newMatrix(cols, rows);
    
    for(unsigned int i = 0; i < cols * rows; ++i)
    {
        unsigned int iX = i % cols;
        unsigned int iY = i / cols;
        newMatrix(iX, iY) = static_cast<U>((*this)(iX, iY));
    }
    
    return newMatrix;
}

template<typename T>
void Matrix<T>::fill()
{
    for(unsigned int i = 0; i < numRows(); ++i)
    {
        for(unsigned int j = 0; j < numCols(); ++j)
        {
            (*this)(j, i) = std::rand() % 10;
        }
    }
}

template<typename T>
bool Matrix<T>::addOrSubCompatible(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    return lhs.numCols() == rhs.numCols() && lhs.numRows() == rhs.numRows();
}

template<typename T>
bool Matrix<T>::multiplyCompatible(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    return lhs.numCols() == rhs.numRows();
}
