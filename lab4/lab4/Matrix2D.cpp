#include "Matrix2D.h"

Matrix2D::Matrix2D(unsigned int iSize):MatrixBase(iSize) {
	matrix = new int* [iSize];
	for (unsigned int i = 0; i < iSize; i++)
		matrix[i] = new int[iSize];
}
int Matrix2D::element(unsigned int i, unsigned int j) {
	return matrix[i][j];
}

int& Matrix2D::elementAddress(unsigned int i, unsigned int j) {
	return matrix[i][j];
}

void Matrix2D::operator*=(int iMult) {
	for (unsigned int i = 0; i < m_size; i++)
		for (unsigned int j = 0; j < m_size; j++)
			matrix[i][j] *= iMult;
}

void Matrix2D::operator+=(Matrix2D iMatrix) {
	unsigned int size;
	if (iMatrix.m_size >= m_size)
		size = iMatrix.m_size;
	else
		size = m_size;
	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			matrix[i][j] += iMatrix.matrix[i][j];
}

std::ostream& operator<<(std::ostream& os, const Matrix2D& iMatrix)
{
	for (unsigned int i = 0; i < iMatrix.m_size; i++)
	{
		for (unsigned int j = 0; j < iMatrix.m_size; j++)
			os << iMatrix.matrix[i][j] << ' ';
		os << '\n';
	}
	return os;
}
