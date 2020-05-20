#include "Matrix2D.h"

Matrix2D::Matrix2D() :MatrixBase(3) {}

std::ostream& operator<<(std::ostream& os, Matrix3D& iMatrix)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
			os << iMatrix.element(i, j) << ' ';
		os << '\n';
	}
	return os;
}