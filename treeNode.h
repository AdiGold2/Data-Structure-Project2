#pragma once
#include "Pair.h"
class treeNode
{
private:
	Pair val;
	treeNode* left = nullptr, * right = nullptr;
public:
	static int counter;
	treeNode() { counter++; }
	treeNode(Pair item, treeNode* left, treeNode* right);
	treeNode(char c);
	treeNode(const treeNode& other);
	~treeNode();

	/*****Getters*****/
	Pair& getVal() { return val; }
	char getData() const { return val.getData(); }
	int getFreq() const { return val.getFrequency(); }
	treeNode* getLeft() const { return left; }
	treeNode* getRight() const { return right; }

	/*****Setters*****/
	bool setVal(Pair item) { val = item; return true; }
	bool setLeft(treeNode* L) { left = L; return true; }
	bool setRight(treeNode* R) { right = R; return true; }

	bool isLeaf() const { return (left == nullptr && right == nullptr); }
	void operator=(const treeNode& other);
};

