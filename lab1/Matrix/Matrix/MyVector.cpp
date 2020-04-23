#include "MyVector.h"

MyVector::Itterator::Itterator(int number) {
	value = number;
	next = nullptr;
}

MyVector::MyVector() {
	count = 0;
	head = nullptr;
	tail = nullptr;
}

void MyVector::AddValue(int number) {
	if (head == nullptr)
	{
		head = new Itterator(number);
		tail = head;
	}
	else if (head == tail)
	{
		tail = new Itterator(number);
		head->next = tail;
	}
	else
	{
		tail->next = new Itterator(number);
		tail = tail->next;
	}
	count++;
}