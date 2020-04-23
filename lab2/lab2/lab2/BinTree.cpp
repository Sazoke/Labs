#include "BinTree.h"

BinTree::BinTree(int value) {
	head = new NodeTree(value);
}

BinTree::BinTree() :BinTree(0) {};

void BinTree::Insert(int value) {
	AddNewValue(head, value);
}

void BinTree::AddNewValue(NodeTree* node, int value)
{
	if (node->GetValue() == value)
		return;
	if (value < node->GetValue())
		if (node->GetLessNode() == nullptr)
			node->SetLessNode(new NodeTree(value));
		else
			AddNewValue(node->GetLessNode(), value);
	else if (value > node->GetValue())
		if (node->GetMoreNode() == nullptr)
			node->SetMoreNode(new NodeTree(value));
		else
			AddNewValue(node->GetMoreNode(), value);
}

NodeTree* BinTree::Find(int value) {
	return FindValue(head, value);
}

NodeTree* BinTree::FindValue(NodeTree* node, int value) {
	if (node->GetValue() == value)
		return node;
	if (value < node->GetValue())
		if (node->GetLessNode() == nullptr)
			return nullptr;
		else
			FindValue(node->GetLessNode(), value);
	else if (value > node->GetValue())
		if (node->GetMoreNode() == nullptr)
			return nullptr;
		else
			FindValue(node->GetMoreNode(), value);
}

BinTree::~BinTree() {
	RemoveNode(head);
}

void BinTree::RemoveNode(NodeTree* node) {
	if (node->GetLessNode() == nullptr)
	{
		if (node->GetMoreNode() == nullptr)
			delete node;
		else
			RemoveNode(node->GetMoreNode());
	}
	else
		RemoveNode(node->GetLessNode());
}