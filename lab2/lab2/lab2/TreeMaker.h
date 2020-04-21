#pragma once
#include <iostream>
#include"BinTree.h"
class TreeMaker
{
private:
	void AddToTree(BinTree* tree, int* begin, int index, int length) {
		if (length == 0)
			return;
		tree->Insert(*(begin+index + length / 2));
		if (length % 2 == 1)
			AddToTree(tree, begin, index, (length - 1) / 2);
		else
			AddToTree(tree, begin, index, length / 2);
		AddToTree(tree, begin, index + length / 2 + 1, (length - 1) / 2);
	}
public:
	BinTree* CreateMinimalBST(int* begin, int* end) {
		int length = end - begin;
		auto tree = new BinTree(*(begin+(length / 2)));
		if (length % 2 == 1)
			AddToTree(tree, begin, 0, (length - 1) / 2);
		else
			AddToTree(tree, begin, 0, length / 2);
		AddToTree(tree, begin, length / 2 + 1, (length - 1) / 2);
		return tree;
	}
};

