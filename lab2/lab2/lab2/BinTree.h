#pragma once
#include"NodeTree.h"
void AddNewValue(NodeTree*, int);
bool FindValue(NodeTree*, int);

class BinTree
{
private:
	NodeTree* head;
public:
	void AddValue(int);
	bool Contains(int);
};

