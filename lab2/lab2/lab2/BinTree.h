#pragma once
#include"NodeTree.h"
class BinTree
{
private:
	NodeTree* head;
public:
	void AddValue(int);
	bool Contains(int);
};

