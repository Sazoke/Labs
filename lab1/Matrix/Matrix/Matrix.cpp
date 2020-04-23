//Соловьев Иван РИ-280001

#include <iostream>
#include "Matrix3x3.h"
#include "MatrixNxN.h"
#include "MyVector.h"

using namespace std;

void ShowMatrix3x3();
void ShowMatrixNxN();
void ShowRemove();
void ShowLast5Element();

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
	MyVector* vec = new MyVector();
	for (int i = 0; i < 5; i++)
	{
		vec->AddValue(1);
		vec->AddValue(i);
	}
	MyVector::Itterator* it = vec->head;
	MyVector* newVector = new MyVector();

	for (int i = 0; i < vec->count; i++)
	{
		bool isSkip = false;
		MyVector::Itterator* newIt = newVector->head;
		for (int j = 0; j < newVector->count; j++)
		{
			if (it->value == newIt->value)
			{
				isSkip = true;
				break;
			}
			newIt = newIt->next;
		}
		if (isSkip)
		{
			it = it->next;
			continue;
		}
		newVector->AddValue(it->value);
		it = it->next;
	}
}

void ShowLast5Element() {
	MyVector vec = MyVector();
	for (int i = 0; i < 10; i++)
	{
		vec.AddValue(i);
	}
	MyVector::Itterator* it = vec.head;

	int count = 0;
	MyVector::Itterator* last5Element = nullptr;
	while (it != vec.tail)
	{
		count++;
		it = it->next;
		if (count == 5)
			last5Element = vec.head;
		if (count > 5)
			last5Element = last5Element->next;
	}
	int value = last5Element->value;
}