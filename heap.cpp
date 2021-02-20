#include "heap.h"

heap::heap(int max)
{
	data = new treeNode* [max];
	maxSize = max;
	heapSize = 0;
	allocated = true;
}
heap::heap(treeNode** arr, int size)
{
	heapSize = maxSize = size;
	data = arr;
	allocated = false;
	for (int i = (size / 2)-1; i >= 0; i--)
		FixHeap(i);
	
}
heap::~heap()
{
	if (allocated)
		delete[] data;
	data = nullptr;
}
void heap::FixHeap(int node)
{
	int M = node;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && (data[left]->getFreq() < data[node]->getFreq()))
		M = left;
	if ((right < heapSize) && (data[right]->getFreq() < data[node]->getFreq()))
		M = ((data[left]->getFreq() < data[right]->getFreq()) ? left : right);
	if (M != node )
	{
		swap(data[node], data[M]);
		FixHeap(M);
	}
}
treeNode* heap::Min()
{
	return data[0];
}
treeNode* heap::deleteMin()
{
	if (heapSize < 1)
		exit(-1);
	treeNode* min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return min;
}
void heap::insert(treeNode* node)
{
	if (heapSize == maxSize)
		exit(-1);
	int i = heapSize;
	heapSize++;
	while ((i > 0) && (data[Parent(i)]->getFreq() > node->getFreq()))
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = node;
}
int heap::Left(int node)
{
	return (2 * node + 1);
}
int heap::Right(int node)
{
	return (2 * node + 2);
}
int heap::Parent(int node)
{
	return ((node - 1) / 2);
}