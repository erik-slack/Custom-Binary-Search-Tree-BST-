#include "BST.h"
using namespace std;

BST::BST() {
	root = NULL;
}
BST::~BST() {
	clear();
	root = NULL;
	
}

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
Node* BST::getRootNode(){
	return root;
}

/*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool BST::add(int data){
	bool was_added = false;
	
	if (root == NULL){
		root = new Node;
		root->data = data;
		was_added = true;
	} else {
		if (contains(data, root) == NULL){
			root = recursiveAdd(data, root);
			was_added = true;
		} else {
			was_added = false;
		}
	}
	
	return was_added;
}

Node* BST::recursiveAdd(int data, Node* current_search){
	if (current_search == NULL){
		Node* location_added = new Node;
		location_added->data = data;
		return location_added;
	}
	
	if (data > current_search->data){
		current_search->right_child = recursiveAdd(data, current_search->right_child);
	} else {
		current_search->left_child = recursiveAdd(data, current_search->left_child);
	}
	
	return current_search;
}

Node* BST::contains(int data, Node* current_search){
	if (current_search == NULL){return NULL;}
	
	if (current_search->data == data){
		return current_search;
	} else if (current_search->data < data){ // && current_search->right_child != NULL
		return contains(data, current_search->right_child);
	} else if (current_search->data > data){
		return contains(data, current_search->left_child);
	}
	
	return current_search;
}

void BST::print(Node* current_print){
	if (current_print == NULL){return;}
	
	if(current_print->left_child == NULL){
	} else {
		cout << current_print->left_child->data;
	}
	cout << " and right child = ";
	if(current_print->right_child == NULL){
		cout << "NULL";
	} else {
		cout << current_print->right_child->data;
	}
	cout << endl;
	
	print(current_print->right_child);
	print(current_print->left_child);
}

/*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
bool BST::remove(int data){
	bool was_removed = false;
	if (root == NULL){
		// DO NOTHING
	} else if ((contains(data, root))->data == data){
		root = recursiveRemove(data, root);
		was_removed = true;
	} else {
		// DO NOTHING
	}
	
	return was_removed;
}

Node* BST::recursiveRemove(int data, Node* current_search){
	if (current_search == NULL){
		return NULL;
	} else if (current_search->data < data){
		current_search->right_child = recursiveRemove(data, current_search->right_child);
		return current_search;
	} else if (current_search->data > data){
		current_search->left_child = recursiveRemove(data, current_search->left_child);
		return current_search;
	} else {
		if (current_search->left_child == NULL){
			Node* temp = current_search->right_child;
			delete current_search;
			return temp;
		} else {
			current_search->left_child = IOP(current_search->left_child, current_search);
			return current_search;
		}
	}

	return current_search;
}

Node* BST::IOP(Node* current, Node* node_to_remove){
	if (current->right_child == NULL){}
	if (current->right_child != NULL){
		current->right_child = IOP(current->right_child, node_to_remove);
		return current;
	} else {
		node_to_remove->data = current->data;
		Node* temp = current->left_child;
		delete current;
		return temp;
	}	
}

/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
void BST::clear(){
	while (root != NULL){
		remove(root->data);
	}
}
