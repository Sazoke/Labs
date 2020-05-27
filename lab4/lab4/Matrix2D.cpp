#include "Matrix2D.h"

Matrix2D::Matrix2D() :MatrixBase(2) {}

int Matrix2D::element(unsigned int i, unsigned int j) const
{
	return matrix[i][j];
}

int& Matrix2D::elementAddress(unsigned int i, unsigned int j)
{
	return matrix[i][j];
}