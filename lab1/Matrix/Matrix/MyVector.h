#pragma once
class MyVector
{
public:
	class Itterator
	{
	public:
		Itterator(int);
		int value;
		Itterator* next;
		
	};

	Itterator* head;
	Itterator* tail;
	int count;

	MyVector();
	void AddValue(int);
};

