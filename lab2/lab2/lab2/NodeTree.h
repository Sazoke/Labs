#pragma once
class NodeTree
{
public:
	int value;
	NodeTree* more;
	NodeTree* less;
	NodeTree(int);
};

