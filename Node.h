#pragma once
//#include "BST.h"
#include <iostream>

class Node {
friend class BST;
private:
	int data;
	Node* left_child;
	Node* right_child;

public:
	Node();
	~Node();

// ANALYZERS
	int getData();
	Node* getLeftChild();
	Node* getRightChild();
};

