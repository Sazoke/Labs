#include "MatrixBase.h"

MatrixBase::MatrixBase(unsigned int iSize) {
	m_size = iSize;
}

unsigned int MatrixBase::size() const {
	return m_size;
}

void MatrixBase::operator*=(int iMult) {
	for (unsigned int i = 0; i < m_size; i++)
		for (unsigned int j = 0; j < m_size; j++)
			elementAddress(i, j) *= iMult;
}

void MatrixBase::operator+=(MatrixBase iMatrix) {
	unsigned int size;
	if (iMatrix.m_size >= m_size)
		size = iMatrix.m_size;
	else
		size = m_size;
	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			elementAddress(i, j) += iMatrix.element(i, j);
}

std::ofstream& operator<<(std::ofstream& os, MatrixBase& iMatrix)
{
	for (unsigned int i = 0; i < iMatrix.size(); i++)
	{
		for (unsigned int j = 0; j < iMatrix.size(); j++)
			os << iMatrix.element(i, j) << ' ';
		os << '\n';
	}
	return os;
}