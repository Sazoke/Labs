#include "Matrix3x3.h"

Matrix3x3::Matrix3x3() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = 0;
}

const int Matrix3x3::element(const int i, const int j) {
	return matrix[i][j];
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = (int)(rand() * (1.0 / ((double)RAND_MAX + 1)) * (maxVal - minVal) + minVal);
}

const int Matrix3x3::sumPrincipalDiag() {
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += matrix[i][i];
	return sum;
}

const int Matrix3x3::sumSecondaryDiag() {
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += matrix[i][2 - i];
	return sum;
}

const int Matrix3x3::productPrincipalDiag() {
	int product = 1;
	for (int i = 0; i < 3; i++)
		product *= matrix[i][i];
	return product;
}

const int Matrix3x3::productSecondaryDiag() {
	int product = 1;
	for (int i = 0; i < 3; i++)
		product *= matrix[i][2 - i];
	return product;
}

const int Matrix3x3::sumRow(const int iRow) {
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += matrix[iRow][i];
	return sum;
}

const int Matrix3x3::minColumn(const int iCol) {
	int min = matrix[0][iCol];
	for (int i = 1; i < 3; i++)
		if (min > matrix[i][iCol])
			min = matrix[i][iCol];
	return min;
}

const int Matrix3x3::maxColumn(const int iCol) {
	int max = matrix[0][iCol];
	for (int i = 1; i < 3; i++)
		if (max < matrix[i][iCol])
			max = matrix[i][iCol];
	return max;
}