#pragma once
#include "TreeNode.h"
class heap
{
private:
	treeNode** data;
	int maxSize;
	int heapSize;
	bool allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	heap(int max);
	heap(treeNode** arr, int size);
	~heap();
	heap(const heap& other) = delete;
	treeNode* Min();
	treeNode* deleteMin();
	void insert(treeNode* node);
	void makeEmpty() { heapSize = 0; }
	bool isEmpty() { return (heapSize == 0); }
	void operator=(const heap& other) = delete;
};
