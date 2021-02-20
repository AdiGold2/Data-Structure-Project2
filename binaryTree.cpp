#include "binaryTree.h"

binaryTree::~binaryTree()
{
	if (root)
		delete(root);
}
