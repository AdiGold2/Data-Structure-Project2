#include "binarySearchTree.h"

binarySearchTree::binarySearchTree()
{
	root = nullptr;
}
binarySearchTree::binarySearchTree(treeNode* root) : root(root) {}
treeNode* binarySearchTree::Find(char c)   //returns tree node with the matching char data,nullptr if not found
{
	treeNode* tmp = root;
	while (tmp)
	{
		if (c == tmp->getData())
			return tmp;
		else if (c < tmp->getData())
			tmp = tmp->getLeft();
		else
			tmp = tmp->getRight();
	}
	return nullptr;
}
treeNode* binarySearchTree::FindParent(char c)  //returns parent of the node with given char data
{
	treeNode* tmp = root;
	treeNode* parent = nullptr;
	while (tmp)
	{
		if (c == tmp->getData())
			return parent;
		parent = tmp;
		if (c < tmp->getData())
			tmp = tmp->getLeft();
		else if (c > tmp->getData())
			tmp = tmp->getRight();
	}
	return nullptr;
}
void binarySearchTree::Insert(char c)   //insert new node with given char to it's appropriate place inside the  BST
{
	treeNode* tmp = Find(c);
	if (tmp != nullptr)                //the char exist
		tmp->getVal().increaseFreq();  //add one to frequency counter
	else  //tmp=nullptr
	{
		tmp = root;
		treeNode* parent = nullptr;
		treeNode* newNode;
		while (tmp)
		{
			parent = tmp;
			if (c < tmp->getData())
				tmp = tmp->getLeft();
			else
				tmp = tmp->getRight();
		}
		newNode = new treeNode(c);
		if (parent == nullptr)
			root = newNode;
		else if (c < parent->getData())
			parent->setLeft(newNode);
		else
			parent->setRight(newNode);
	}
}
void binarySearchTree::Delete(char c)  //remove node from search tree by given char
{
	treeNode* tmp = Find(c);
	treeNode* parent = FindParent(c);
	if (parent == nullptr)
	{
		treeNode* max = Max(tmp->getLeft());
		swap(max, tmp);
		Delete(max->getData()); //recursive call with one or zero sons
		root = tmp;
	}
	if (parent->getData() > tmp->getData())   //tmp is left son
	{
		if (tmp->isLeaf())
			parent->setLeft(nullptr);
		else if (tmp->getLeft() == nullptr)   //tmp has only right child
			parent->setLeft(tmp->getRight());
		else if (tmp->getRight() == nullptr)  //tmp has only left child
			parent->setLeft(tmp->getLeft());
		else  //tmp has two sons
		{
			treeNode* max = Max(tmp->getLeft());
			swap(max, tmp);
			Delete(max->getData()); //recursive call with one or zero sons
		}
	}
	else  //tmp is right son
	{
		if (tmp->isLeaf())
			parent->setRight(nullptr);
		else if (tmp->getLeft() == nullptr)   //tmp has only right child
			parent->setRight(tmp->getRight());
		else if (tmp->getRight() == nullptr)  //tmp has only left child
			parent->setRight(tmp->getLeft());
		else  //tmp has two sons
		{
			treeNode* max = Max(tmp->getLeft());
			swap(max, tmp);
			Delete(max->getData()); //recursive call with one or zero sons
		}
	}
	delete tmp;
}
treeNode* binarySearchTree::Max(treeNode* root)  //returns maximal data tree node of BST
{
	treeNode* tmp = root;
	while (tmp->getRight())
		tmp = tmp->getRight();
	return tmp;
}
void binarySearchTree::swap(treeNode* a, treeNode* b)
{
	Pair tmp = a->getVal();
	treeNode* tmpLeft = a->getLeft();
	treeNode* tmpRigth = a->getRight();
	a->setVal(b->getVal());
	a->setLeft(b->getLeft());
	a->setRight(b->getRight());
	b->setVal(tmp);
	b->setLeft(tmpLeft);
	b->setRight(tmpRigth);
}

void binarySearchTree::makeArr(treeNode** arr, treeNode* root) //converts tree into treenodes array recursively
{
	static int i = 0;
	if (root->getLeft())
		makeArr(arr, root->getLeft());
	if (root->getRight())
		makeArr(arr, root->getRight());
	arr[i] = root;
	i++;
	root->setLeft(nullptr);
	root->setRight(nullptr);
}