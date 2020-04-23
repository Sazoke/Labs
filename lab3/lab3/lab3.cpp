
#include <iostream>
#include <time.h>
using namespace std;
int Search(int*, int*, int);
void QuickSortRecursion(int*, int, int);
void QuickSortNotRecursion(int*, int, int);
int BSearchRecursion(int*, int, int, int);
int BSearchNotRecursion(int*, int, int, int);

int main()
{
	int arr[100];
	for (int i = 0; i < 100; i++)
		arr[i] = rand() % (21) - 10;
	cout << Search(begin(arr), end(arr), -6);
	cout << '\n';
	for (int i = 0; i < 100; i++)
		cout << arr[i] << ' ';
	cout << '\n';
	QuickSortRecursion(begin(arr), 0, 99);
	for (int i = 0; i < 100; i++)
		cout << arr[i] << ' ';
	cout << '\n';
	cout << BSearchNotRecursion(begin(arr), -1, 100, -6);
}

int Search(int* begin, int* end, int value) {
	for (int* i = begin; i < end; i++)
		if (*i == value)
			return i - begin;
}

void QuickSortRecursion(int* begin, int left, int right) {
	int i = left;
	int j = right;
	int mid = begin[(left + right) / 2];
	while (i <= j) {
		while (begin[i] < mid)
			i++;
		while (begin[j] > mid)
			j--;
		if (i <= j)
		{
			int box = begin[i];
			begin[i] = begin[j];
			begin[j] = box;
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSortRecursion(begin, left, j);
	if (right > i)
		QuickSortRecursion(begin, i, right);
}

void QuickSortNotRecursion(int* begin, int left, int right) {
	while (true) {
		int i = left;
		int j = right;
		int mid = begin[(left + right) / 2];
		while (true) {
			i = left;
			j = right;
			mid = begin[(left + right) / 2];
			while (i <= j) {
				while (begin[i] < mid)
					i++;
				while (begin[j] > mid)
					j--;
				if (i <= j)
				{
					int box = begin[i];
					begin[i] = begin[j];
					begin[j] = box;
					i++;
					j--;
				}
			}
			if (left >= j)
				break;
			right = j;
		}
		if (right <= i)
			return;
		left = i;
	}
	
}

int BSearchRecursion(int* begin, int left, int right, int value) {
	if (left + 1 == right)
		return -1;
	int mid = begin[(left + right) / 2];
	if (value < mid)
		return BSearchRecursion(begin, left, (left + right) / 2, value);
	else if (value > mid)
		return BSearchRecursion(begin, (left + right) / 2, right, value);
	else
		return(left + right) / 2;
}

int BSearchNotRecursion(int* begin, int left, int right, int value) {
	while (true)
	{
		if (left + 1 == right)
			return -1;
		int mid = begin[(left + right) / 2];
		if (value < mid)
			right = (left + right) / 2;
		else if (value > mid)
			left = (left + right) / 2;
		else
			return(left + right) / 2;
	}
	
}