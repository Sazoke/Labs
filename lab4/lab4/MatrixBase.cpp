#include "MatrixBase.h"

MatrixBase::MatrixBase(unsigned int iSize) {
	m_size = iSize;
	matrix = new int* [m_size];
	for (unsigned int i = 0; i < m_size; i++)
		matrix[i] = new int[m_size];
}

const unsigned int MatrixBase::size() {
	return m_size;
}

int MatrixBase::element(unsigned int i, unsigned int j) {
	return matrix[i][j];
}

int& MatrixBase::elementAddress(unsigned int i, unsigned int j) {
	return matrix[i][j];
}

void MatrixBase::operator*=(int iMult) {
	for (unsigned int i = 0; i < m_size; i++)
		for (unsigned int j = 0; j < m_size; j++)
			matrix[i][j] *= iMult;
}

void MatrixBase::operator+=(MatrixBase iMatrix) {
	unsigned int size;
	if (iMatrix.m_size >= m_size)
		size = iMatrix.m_size;
	else
		size = m_size;
	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			matrix[i][j] += iMatrix.matrix[i][j];
}

std::ostream& operator<<(std::ostream& os, MatrixBase& iMatrix)
{
	for (unsigned int i = 0; i < iMatrix.size(); i++)
	{
		for (unsigned int j = 0; j < iMatrix.size(); j++)
			os << iMatrix.element(i, j) << ' ';
		os << '\n';
	}
	return os;
}