#include "NodeTree.h"

NodeTree::NodeTree(int value) {
	this->value = value;
	less = nullptr;
	more = nullptr;
}