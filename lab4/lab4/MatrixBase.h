#pragma once
#include <fstream>

class MatrixBase
{
public:
	unsigned int size() const;
	virtual int element(unsigned int i, unsigned int j) const;
	virtual int& elementAddress(unsigned int i, unsigned int j);
	void operator *=(int iMult);
	void operator +=(MatrixBase iAdd);
	friend std::ofstream& operator<<(std::ofstream& os, MatrixBase& iMatrix);
protected:
	MatrixBase(unsigned int iSize);
private:
	unsigned int m_size;
};