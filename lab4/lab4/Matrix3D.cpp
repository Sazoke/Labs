#include "Matrix3D.h"

Matrix3D::Matrix3D(unsigned int iSize) :MatrixBase(iSize) {
	matrix = new int** [iSize];
	for (unsigned int i = 0; i < iSize; i++)
	{
		matrix[i] = new int* [iSize];
		for (unsigned int j = 0; j < iSize; j++)
			matrix[i][j] = new int[iSize];
	}
}

const int Matrix3D::element(unsigned int i, unsigned int j, unsigned int k) {
	return matrix[i][j][k];
}
int& Matrix3D::elementAddress(unsigned int i, unsigned int j, unsigned int k) {
	return matrix[i][j][k];
}

void Matrix3D::operator*=(int iMult) {
	for (unsigned int i = 0; i < m_size; i++)
		for (unsigned int j = 0; j < m_size; j++)
			for (unsigned int k = 0; j < m_size; k++)
				matrix[i][j][k] *= iMult;
}

void Matrix3D::operator+=(Matrix3D iMatrix) {
	unsigned int size;
	if (iMatrix.m_size >= m_size)
		size = iMatrix.m_size;
	else
		size = m_size;
	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			for (unsigned int k = 0; j < m_size; k++)
				matrix[i][j][k] += iMatrix.matrix[i][j][k];
}

std::ostream& operator<<(std::ostream& os, const Matrix3D& iMatrix)
{
	for (unsigned int i = 0; i < iMatrix.m_size; i++)
	{
		for (unsigned int j = 0; j < iMatrix.m_size; j++)
		{
			for (unsigned int k = 0; j < iMatrix.m_size; k++)
				os << iMatrix.matrix[i][j][k] << ' ';
			os << '\n';
		}
		os << '\n' << '\n';
	}
	return os;
}