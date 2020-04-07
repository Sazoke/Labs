#pragma once
#include <random>
class Matrix3x3
{
private:
	int matrix[3][3];
public:
	Matrix3x3();
	const int element(const int, const int);
	void setElement(const int, const int, const int);
	void fillRandomElements(const int, const int);
	const int sumPrincipalDiag();
	const int sumSecondaryDiag();
	const int productPrincipalDiag();
	const int productSecondaryDiag();
	const int sumRow(const int);
	const int minColumn(const int);
	const int maxColumn(const int);
};

