// Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Matrix3x3.h"
#include "MatrixNxN.h"
#include <vector>

using namespace std;

void ShowMatrix3x3();
void ShowMatrixNxN();
void ShowRemove();
void ShowLast5Element();
void RemoveDubl(vector<int>*);
int FindLast5Element(vector<int>*);

int main()
{
	ShowMatrix3x3();
	cout << '\n' << '\n';
	ShowMatrixNxN();
	cout << '\n' << '\n';
	ShowRemove();
	cout << '\n' << '\n';
	ShowLast5Element();
}

void ShowMatrix3x3() {
	Matrix3x3 matrix = Matrix3x3();
	matrix.fillRandomElements(-10, 10);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << matrix.element(i, j) << ' ';
		cout << '\n';
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "sum " << i << " row = " << matrix.sumRow(i) << '\n';
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "min " << i << " column = " << matrix.minColumn(i) << '\n';
		cout << "max " << i << " column = " << matrix.maxColumn(i) << '\n';
	}
	cout << "sum principal diag = " << matrix.sumPrincipalDiag() << '\n' << "product principal diag = " << matrix.productPrincipalDiag() << '\n';
	cout << "sum secondary diag = " << matrix.sumSecondaryDiag() << '\n' << "product secondary diag = " << matrix.productSecondaryDiag() << '\n';
}

void ShowMatrixNxN() {
	int size = 10;
	MatrixNxN matrix = MatrixNxN(size);
	matrix.fillRandomElements(-10, 10);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << matrix.element(i, j) << ' ';
		cout << '\n';
	}
	for (int i = 0; i < size; i++)
	{
		cout << "sum " << i << " row = " << matrix.sumRow(i) << '\n';
	}
	for (int i = 0; i < size; i++)
	{
		cout << "min " << i << " column = " << matrix.minColumn(i) << '\n';
		cout << "max " << i << " column = " << matrix.maxColumn(i) << '\n';
	}
	cout << "sum principal diag = " << matrix.sumPrincipalDiag() << '\n' << "product principal diag = " << matrix.productPrincipalDiag() << '\n';
	cout << "sum secondary diag = " << matrix.sumSecondaryDiag() << '\n' << "product secondary diag = " << matrix.productSecondaryDiag() << '\n';
}

void ShowRemove() {
	vector<int> vec = vector<int>();
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(1);
		vec.push_back(i);
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << '\n';
	RemoveDubl(&vec);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
}

void RemoveDubl(vector<int>* vec) {
	vector<int> result = vector<int>();
	for (int i = 0; i < (*vec).size(); i++)
	{
		bool isSkip = false;
		for (int j = 0; j < result.size(); j++)
		{
			if ((*vec)[i] == result[j])
			{
				isSkip = true;
				break;
			}
		}
		if (isSkip)
			continue;
		result.push_back((*vec)[i]);
	}
	*vec = result;
}

void ShowLast5Element() {
	vector<int> vec = vector<int>();
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(1);
		vec.push_back(i);
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << '\n';
	cout << FindLast5Element(&vec);
}

int FindLast5Element(vector<int>* vec) {
	auto a = vec->end();
	for (int i = 0; i < 5; i++)
		a--;
	return *a;
}