#pragma once
#include <fstream>

class MatrixBase
{
public:
	const unsigned int size();
	const virtual int element(unsigned int i, unsigned int j);
	const virtual int& elementAddress(unsigned int i, unsigned int j);
	virtual void operator *=(int iMult);
	virtual void operator +=(MatrixBase iAdd);
	friend std::ofstream& operator<<(std::ofstream& os, MatrixBase& iMatrix);
protected:
	int** matrix = nullptr;
	MatrixBase(unsigned int iSize);
	unsigned int m_size;
};