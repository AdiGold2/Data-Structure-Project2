#include "treeNode.h"

int treeNode::counter;
treeNode::~treeNode()
{
	if (left!=nullptr)
		delete left;
	if (right!=nullptr)
		delete right;
}
treeNode::treeNode(Pair item, treeNode* left, treeNode* right)
{
	val = item;
	left = left;
	right = right;
	counter++;
}
treeNode::treeNode(char c)
{
	val.setData(c);
	val.setFreq(1);
	left = nullptr;
	right = nullptr;
	counter++;
}
treeNode::treeNode(const treeNode& other)
{
	*this = other;
}
void treeNode::operator=(const treeNode& other)
{
	this->val = other.val;
	this->left = other.left;
	this->right = other.right;
}
