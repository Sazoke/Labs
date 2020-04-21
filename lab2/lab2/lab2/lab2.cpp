// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"BinTree.h"
#include"TreeMaker.h"
using namespace std;
const int length = 9;

int main()
{
	int arr[length];
	for (int i = 0; i < length; i++)
		arr[i] = i;
	auto tree = TreeMaker().CreateMinimalBST(begin(arr), end(arr));
}

