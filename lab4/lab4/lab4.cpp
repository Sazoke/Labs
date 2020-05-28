#include <iostream>
#include "MatrixBase.h"
#include "Matrix2D.h"
#include "Matrix3D.h"
using namespace std;

void Fill(MatrixBase&);

int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;
    Fill(m2a);
    Fill(m2b);
    Fill(m3a);
    Fill(m3b);
    cout << "m2a = " << '\n' << m2a << '\n';
    cout << "m2b = " << '\n' << m2b << '\n';
    cout << "m3a = " << '\n' << m3a << '\n';
    cout << "m3b = " << '\n' << m3b << '\n';
    m2a *= 5;
    cout << "m2a * 5 = " << '\n' << m2a << '\n';
    m2a += m2b;
    cout << " m2a + m2b = " << '\n' << m2a << '\n';
    m3a *= 9;
    cout << "m3a * 9 = " << '\n' << m3a << '\n';
    m3a += m3b;
    cout << " m3a + m3b = " << '\n' << m3a << '\n';
    return 0;
}


void Fill(MatrixBase& matrix)
{
    for (unsigned int i = 0; i < matrix.size(); i++)
        for (unsigned int j = 0; j < matrix.size(); j++)
            matrix.elementAddress(i, j) = 1 + j + i * matrix.size();
}