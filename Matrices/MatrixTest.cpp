#ifdef MATRIX_TEST

#include "Matrix.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
void fillMatrix(Matrix<T>& m);

int main(int argc, char** argv)
{
    std::srand(std::time(0));
    
    Matrix<int> m1(3, 3);
    Matrix<int> m2(3, 3);
    
    fillMatrix(m1);
    fillMatrix(m2);
    
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
    
    return 0;
}

template<typename T>
void fillMatrix(Matrix<T>& m)
{
    for(unsigned int i = 0; i < m.numRows(); ++i)
    {
        for(unsigned int j = 0; j < m.numCols(); ++j)
        {
            m(j, i) = std::rand() % 10;
        }
    }
}

#endif
