#pragma once
class MatrixBase
{
protected:
	int** matrix = nullptr;
	MatrixBase(unsigned int iSize);
	unsigned int m_size;
public:
	const unsigned int size();
	virtual int element(unsigned int i, unsigned int j);
	virtual int& elementAddress(unsigned int i, unsigned int j);
	virtual void operator *=(int iMult);
	virtual void operator +=(MatrixBase iAdd);
};

