#pragma once
class NodeTree
{
private:
	int value;
	NodeTree* more;
	NodeTree* less;

public:
	NodeTree();
	NodeTree(int);
	NodeTree* GetMoreNode();
	void SetMoreNode(NodeTree*);
	NodeTree* GetLessNode();
	void SetLessNode(NodeTree*);
	int GetValue();
	void SetValue(int);
};

