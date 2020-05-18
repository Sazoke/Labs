#pragma once
#include "MatrixBase.h"
#include <ostream>
class Matrix3D :
	public MatrixBase
{
private:
	int*** matrix;
public:
	Matrix3D(unsigned int iSize);
	const int element(unsigned int i, unsigned int j, unsigned int k);
	int& elementAddress(unsigned int i, unsigned int j, unsigned int k);
	void operator*=(int iMult) override;
	void operator+=(Matrix3D iMatrix);
	friend std::ostream& operator<< (std::ostream& os, const Matrix3D& iMatrix);
};

