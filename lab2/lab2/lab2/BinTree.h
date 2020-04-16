#pragma once
#include"NodeTree.h"

class BinTree
{
private:
	NodeTree* head;
	void AddNewValue(NodeTree*, int);
	NodeTree* FindValue(NodeTree*, int);
	void RemoveNode(NodeTree*);
public:
	BinTree();
	BinTree(int);
	~BinTree();

	void Insert(int);
	NodeTree* Find(int);
};

