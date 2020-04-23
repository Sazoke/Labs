// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"BinTree.h"
using namespace std;
const int length = 9;
BinTree* CreateMinimalBST(int*, int, int);
void AddToTree(BinTree*, int*, int, int);

int main()
{
	int arr[length];
	for (int i = 0; i < length; i++)
		arr[i] = i;
	auto tree = CreateMinimalBST(begin(arr), 0, length - 1);
}

BinTree* CreateMinimalBST(int* begin, int left, int right) {
	int length = right - left + 1;
	auto tree = new BinTree(*(begin + (length / 2)));
	if (length % 2 == 1)
		AddToTree(tree, begin, 0, ((right - left) - 1) / 2);
	else
		AddToTree(tree, begin, 0, (right - left) / 2);
	AddToTree(tree, begin, (right - left + 1) / 2 + 1, right);
	return tree;
}

void AddToTree(BinTree* tree, int* begin, int left, int right) {
	tree->Insert(*(begin + (right + left) / 2));
	if (left >= right)
		return;
	if ((right - left) % 2 == 0)
		AddToTree(tree, begin, left, (right + left - 1) / 2);
	else
		AddToTree(tree, begin, left, (right + left) / 2);
	AddToTree(tree, begin, (left + right) / 2 + 1, right);

}
