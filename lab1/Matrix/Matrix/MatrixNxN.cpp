#include "MatrixNxN.h"

MatrixNxN::MatrixNxN(const int iDim) {
	size = iDim;
	matrix = new int*[iDim];
	for (int i = 0; i < iDim; i++)
	{
		matrix[i] = new int[iDim];
		for (int j = 0; j < iDim; j++)
			matrix[i][j] = 0;
	}
}

const int MatrixNxN::element(const int i, const int j) {
	return matrix[i][j];
}

void MatrixNxN::fillRandomElements(const int minVal, const int maxVal) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = (int)(rand() * (1.0 / ((double)RAND_MAX + 1)) * (maxVal - minVal) + minVal);
}

const int MatrixNxN::sumPrincipalDiag() {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += matrix[i][i];
	return sum;
}

const int MatrixNxN::sumSecondaryDiag() {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += matrix[i][size - 1 - i];
	return sum;
}

const int MatrixNxN::productPrincipalDiag() {
	int product = 1;
	for (int i = 0; i < size; i++)
		product *= matrix[i][i];
	return product;
}

const int MatrixNxN::productSecondaryDiag() {
	int product = 1;
	for (int i = 0; i < size; i++)
		product *= matrix[i][size - 1 - i];
	return product;
}

const int MatrixNxN::sumRow(const int iRow) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += matrix[iRow][i];
	return sum;
}

const int MatrixNxN::minColumn(const int iCol) {
	int min = matrix[0][iCol];
	for (int i = 1; i < size; i++)
		if (min > matrix[i][iCol])
			min = matrix[i][iCol];
	return min;
}

const int MatrixNxN::maxColumn(const int iCol) {
	int max = matrix[0][iCol];
	for (int i = 1; i < size; i++)
		if (max < matrix[i][iCol])
			max = matrix[i][iCol];
	return max;
}

MatrixNxN::~MatrixNxN() {
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}