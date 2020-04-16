#include "NodeTree.h"

NodeTree::NodeTree(int value) {
	this->value = value;
	less = nullptr;
	more = nullptr;
}

NodeTree::NodeTree() :NodeTree(0) {};

NodeTree* NodeTree::GetLessNode() {
	return less;
}

void NodeTree::SetLessNode(NodeTree* newNode) {
	less = newNode;
}

NodeTree* NodeTree::GetMoreNode() {
	return more;
}

void NodeTree::SetMoreNode(NodeTree* newNode) {
	more = newNode;
}

int NodeTree::GetValue() {
	return value;
}

void NodeTree::SetValue(int newValue) {
	value = newValue;
}