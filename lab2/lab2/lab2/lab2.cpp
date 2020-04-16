// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"BinTree.h"
const int length = 9;

BinTree* GetTree(int*, int);
void AddToTree(BinTree*, int*, int, int);

int main()
{
	int arr[length];
	for (int i = 0; i < length; i++)
		arr[i] = i;
	auto tree = GetTree(arr, length);
}

BinTree* GetTree(int* arr, int length) {
	auto tree = new BinTree(arr[length / 2]);
	if (length % 2 == 1)
		AddToTree(tree, arr, 0, (length - 1) / 2);
	else
		AddToTree(tree, arr, 0, length / 2);
	AddToTree(tree, arr, length / 2 + 1, (length - 1) / 2);
	return tree;
}

void AddToTree(BinTree* tree, int arr[], int index, int length) {
	if (length == 0)
		return;
	tree->Insert(arr[index + length / 2]);
	if (length % 2 == 1)
		AddToTree(tree, arr, index, (length - 1) / 2);
	else
		AddToTree(tree, arr, index, length / 2);
	AddToTree(tree, arr, index + length / 2 + 1, (length - 1) / 2);
}