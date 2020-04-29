// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"BinTree.h"
using namespace std;
const int length = 9;
BinTree* tree = nullptr;
BinTree* CreateMinimalBST(int*, int, int);

int main()
{
	int arr[length];
	for (int i = 0; i < length; i++)
		arr[i] = i;
	auto tree = CreateMinimalBST(begin(arr), 0, length - 1);
}

BinTree* CreateMinimalBST(int* begin, int left, int right) {
	int length = right - left + 1;
	if(tree == nullptr)
		tree = new BinTree(*(begin + (length / 2)));
	else
		tree->Insert(*(begin + (right + left) / 2));
	if (length % 2 == 1)
		CreateMinimalBST(begin, left, ((right + left) - 1) / 2);
	else
		CreateMinimalBST(begin, left, (right + left) / 2);
	CreateMinimalBST(begin, (right + left) / 2 + 1, right);
	return tree;
}
