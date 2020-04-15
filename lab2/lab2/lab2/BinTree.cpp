#include "BinTree.h"

void BinTree::AddValue(int value) {
	if (head == nullptr)
	{
		head = new NodeTree(value);
		return;
	}
	AddNewValue(head, value);
}

void AddNewValue(NodeTree* node, int value)
{
	if (node->value == value)
		return;
	if (value < node->value)
		if (node->less == nullptr)
			node->less = new NodeTree(value);
		else
			AddNewValue(node->less, value);
	else if (value > node->value)
		if (node->more == nullptr)
			node->more = new NodeTree(value);
		else
			AddNewValue(node->more, value);
}

bool BinTree::Contains(int value) {
	if (head == nullptr)
		return false;
	return FindValue(head, value);
}

bool FindValue(NodeTree* node, int value) {
	if (node->value == value)
		return true;
	if (value < node->value)
		if (node->less == nullptr)
			return false;
		else
			FindValue(node->less, value);
	else if (value > node->value)
		if (node->more == nullptr)
			return false;
		else
			FindValue(node->more, value);
}