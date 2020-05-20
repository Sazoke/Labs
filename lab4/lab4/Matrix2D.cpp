#include "Matrix2D.h"

Matrix2D::Matrix2D() :MatrixBase(2) {}

std::ostream& operator<<(std::ostream& os, Matrix2D& iMatrix)
{
	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 2; j++)
			os << iMatrix.element(i, j) << ' ';
		os << '\n';
	}
	return os;
}
