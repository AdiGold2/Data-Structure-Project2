#pragma once
#include "treeNode.h"
#include "heap.h"
class binaryTree
{
private:
	treeNode* root = nullptr;
public:
	binaryTree(treeNode* _root) : root(_root) {}
	~binaryTree();
	binaryTree(const binaryTree& other) = delete;

	treeNode* getRoot() const { return root; }
	void operator=(const binaryTree& other) = delete;
};

