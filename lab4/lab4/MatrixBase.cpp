#include "MatrixBase.h"

MatrixBase::MatrixBase(unsigned int iSize) {
	m_size = iSize;
}

const unsigned int MatrixBase::size() {
	return m_size;
}