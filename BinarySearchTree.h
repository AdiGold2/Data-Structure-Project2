#pragma once
#include "TreeNode.h"

class binarySearchTree
{
private:
	treeNode* root;

public:
	binarySearchTree();
	binarySearchTree(treeNode* root);
	~binarySearchTree() {}
	binarySearchTree(const binarySearchTree& other) = delete;

	treeNode* getRoot() const { return root; }

	treeNode* Find(char c);
	void Insert(char c);
	void Delete(char c);
	treeNode* FindParent(char c);
	treeNode* Max(treeNode* root);

	void swap(treeNode* a, treeNode* b);
	void makeArr(treeNode** arr, treeNode* root);
	void operator=(const binarySearchTree& other) = delete;
};

