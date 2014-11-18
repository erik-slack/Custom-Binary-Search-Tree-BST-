#pragma once
#include "BSTInterface.h"
#include "Node.h"
using namespace std;

class BST : public BSTInterface {
private:
	Node* root;
	
public:
	BST();
	~BST();

	/*
	 * A binary search tree (BST), which may sometimes be called an ordered or sorted binary tree, is a node-based data structure where each node references a value, a left child, and a right child. 
	 * Binary search trees are characterized by the following properties:
	 * 	*	The left subtree of a node contains only nodes with values less than the node's value.
	 * 	*	The right subtree of a node contains only nodes with values greater than the node's value.
	 * 	*	There must be no duplicate nodes.
	 * 	*	Both the left and right subtrees of a node also mustbe binary search trees (each subtree must have the first three properties). [Wikipedia]
	 * 
	 * REQUIREMENTS
	 * 
	 * PART 1 - Implement the NodeInterface (5 points)
	 * 	*	Implement the NodeInterface.
	 * 
	 * PART 2 - Add Nodes to the Binary Search Tree (5 points)
	 * 	*	Implement the add method in the BSTInterface. You must use your implementation of NodeInterface properly in the structure of your binary search tree.
	 * 	*	Implement the getRootNode method in the BSTInterface.
	 * 
	 * PART 3 - Remove Nodes from the Binary Search Tree (10 points)
	 * 	*	Implement the remove method in the BSTInterface. You must use your implementation of NodeInterface properly with your binary search tree.
	 * 	*	There are several logically correct ways to remove from a binary search tree. See the requirement notes for instructions on how to remove correctly to pass the test driver.
	 * 
	 * PART 4 - Pass Valgrind (10 points)
	 * 	*	You must pass parts 1 - 3 
	 * 	*	Pass Valgrind to receive credit for this part.
	 * 
	 * REQUIREMENT NOTES
	 * 	*	There are multiple correct methods for removing nodes from a tree; each method may result in a distinct tree. Some conventions need to be used to ensure that your tree properly matches ours. 
	 * 	* 	*	When removing, use the method described on page 476 of the course text. 
	 * 	* 	*	Please refer to this PowerPoint for more detailed information on proper node removal.
	 * 	*	Remember to disallow duplicate entries and to handle the case when the element to be removed is not in the tree.
	 */
	 
	// PART 1 - SETUP
	Node* getRootNode();
	// PART 2 - ADD
	bool add(int data);
	Node* recursiveAdd(int data, Node* current_search);
	Node* contains(int data, Node* current_search);
	void print(Node* current_print);
	// PART 3 - REMOVE
	bool remove(int data);
	Node* recursiveRemove(int data, Node* current_search);
	Node* IOP(Node* current_search, Node* node_to_remove);
	// PART 4 - MEMORY CLEANUP
	void clear();
};



