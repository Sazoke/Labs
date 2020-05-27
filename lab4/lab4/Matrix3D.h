#pragma once
#include "MatrixBase.h"
class Matrix3D :
	public MatrixBase
{
public:
	Matrix3D();
	virtual int element(unsigned int i, unsigned int j) const override;
	virtual int& elementAddress(unsigned int i, unsigned int j) override;
private:
	static const int mSize = 3;
	int matrix[mSize][mSize];
};

