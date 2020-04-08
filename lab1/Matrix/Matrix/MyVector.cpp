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

void MyVector::RemoveAt(int number) {
	if (number == 0) {
		Itterator* removedItem = head;
		head = head->next;
		delete removedItem;
	}
	else {
		Itterator& it = *head;
		for (int i = 0; i < number - 1; i++)
			it = *it.next;
		Itterator* removedItem = (&it)->next;
		(&it)->next = (&it)->next->next;
		delete removedItem;
	}
	count--;
}