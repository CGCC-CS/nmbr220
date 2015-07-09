#ifdef MATRIX_TEST

#include "Matrix.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
void fillMatrix(Matrix<T>& m);

template<typename T>
void printMatrix(const Matrix<T>& m);

int main(int argc, char** argv)
{
    std::srand(std::time(0));
    
    Matrix<int> m1(3, 3);
    Matrix<int> m2(3, 3);
    
    fillMatrix(m1);
    fillMatrix(m2);
    
    std::cout << "matrix 1:\n";
    printMatrix(m1);
    
    std::cout << "matrix 2:\n";
    printMatrix(m2);
    
    Matrix<int> mAdd = m1 + m2;
    Matrix<int> mSub = m1 - m2;
    Matrix<int> mMult = m1 * m2;
    Matrix<int> mScale1 = 3 * m1;
    Matrix<int> mScale2 = m2 * 3;
    
    std::cout << "\nmatrix add:\n";
    printMatrix(mAdd);
    
    std::cout << "matrix sub:\n";
    printMatrix(mSub);
    
    std::cout << "matrix mult:\n";
    printMatrix(mMult);
    
    std::cout << "matrix scale 1:\n";
    printMatrix(mScale1);
    
    std::cout << "matrix scale 2:\n";
    printMatrix(mScale2);
    
    return 0;
}

template<typename T>
void fillMatrix(Matrix<T>& m)
{
    for(int i = 0; i < m.numRows(); ++i)
    {
        for(int j = 0; j < m.numCols(); ++j)
        {
            m(j, i) = std::rand() % 10;
        }
    }
}

template<typename T>
void printMatrix(const Matrix<T>& m)
{
    for(unsigned int i = 0; i < m.numRows(); ++i)
    {
        for(unsigned int j = 0; j < m.numCols(); ++j)
        {
            std::cout << m(j, i) << '\t';
        }
        
        std::cout << '\n';
    }
}

#endif
