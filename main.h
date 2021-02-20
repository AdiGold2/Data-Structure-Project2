#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "binarySearchTree.h"
#include "heap.h"
#include "binaryTree.h"

#define MAXSIZE 128
using namespace std;
treeNode* Huffman(treeNode** arr, int size);
void printSummary(treeNode* node, string str, int* count);

