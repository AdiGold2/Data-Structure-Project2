#include "main.h"

int main()
{
	char fileName[MAXSIZE];       //maxSize=128
	char val;
	cin >> fileName;
	ifstream infile(fileName);
	if (!infile)            //invalid file name
	{
		cout << "Error with file" << endl;
		exit(-1);
	}
	binarySearchTree BST;
	infile.get(val);
	while (!infile.eof())    //looping file reading
	{
		if (!infile.good()) {
			cout << "Error reading" << endl;
			exit(-1);
		}
		BST.Insert(val);
		infile.get(val);
	}
	infile.close();
	int size = BST.getRoot()->counter;            //amount of nodes created
	treeNode** arr = new treeNode * [size];
	BST.makeArr(arr, BST.getRoot());
	treeNode* root = Huffman(arr, size);
	binaryTree BT(root);                   //huffman tree
	int count = 0;
	string str;
	cout << "Character encoding:" << endl;
	printSummary(BT.getRoot(),str,&count);   //final printing process, encoded chars print and final amount of bits calculated
	cout << "Encoded file weight: " << count << " bits" << endl;    
	delete[] arr;
	return 0;
}
void printSummary(treeNode* node, string str,int* count)
{
	string leftStr, rightStr;
	if (node->isLeaf())          //printing leaf, meaning new encoded char
	{
		if (str.size() == 0)
			str = "0";
		*count += (node->getFreq() * str.size());
		if (node->getData() != '\n' && node->getData() != '\t')
			cout << "'" << node->getData() << "' - " << str << endl;
		else                             //case it's endl or tab needs a different treatment
		{
			if(node->getData() == '\n')
				cout << "'\\n' - " << str << endl;
			else
				cout << "'\\t' - " << str << endl;
		}
	}
	else         //not a leaf, add '0' to lefts and '1' to rights
	{
		if (node->getLeft() != nullptr)
		{
			leftStr = str + '0';
			printSummary(node->getLeft(), leftStr,count);
		}
		if (node->getRight() != nullptr)
		{
			rightStr = str + '1';
			printSummary(node->getRight(), rightStr, count);
		}
	}
}
treeNode* Huffman(treeNode** arr, int size)
{
	heap H(arr, size);
	treeNode* node, * left, * right;

	for (int i = 1; i < size; i++)  //huffman algorithm does size-1 iterations
	{
		node = new treeNode();
		left = H.deleteMin();
		right = H.deleteMin();
		node->setLeft(left);
		node->setRight(right);
		node->getVal().setFreq(left->getFreq() + right->getFreq());
		H.insert(node);
	}
	return H.deleteMin();
}