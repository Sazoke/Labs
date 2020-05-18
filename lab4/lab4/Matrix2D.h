#pragma once
#include "MatrixBase.h"
#include <ostream>
class Matrix2D :
	public MatrixBase
{
private:
	int** matrix;
public:
	Matrix2D(unsigned int iSize);
	int element(unsigned int i, unsigned int j) override;
	int& elementAddress(unsigned int i, unsigned int j) override;
	void operator*=(int iMult) override;
	void operator+=(Matrix2D iMatrix);
	friend std::ostream& operator<< (std::ostream& os, const Matrix2D& iMatrix);
};

