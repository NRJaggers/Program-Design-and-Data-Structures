/*
 * BTS.h
 *
 *  Created on: Apr 15, 2020
 *      Author: Nathan Jaggers
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>

using namespace std;

struct BSTNode /// BinarySearchTreeNode
{

  int value;
  BSTNode * left;
  BSTNode * right;

  //Constructors
  	BSTNode(){
  		value = 0 ;
  		left = NULL;
  		right = NULL;
  	}

  	BSTNode(int input){
  	  		value = input ;
  	  		left = NULL;
  	  		right = NULL;
  	  	}
};

class BST // BinarySearchTree
{
  private:
    BSTNode * root;
  public:
  //Constructor
    BST()
  	{
      root = NULL;
    }

  void insert(int value) ;
  /// ------------------------------------------
  void remove(int value) ;
  bool leaf(BSTNode * , BSTNode *);
  bool singleBranch(BSTNode * , BSTNode *);
  void doubleBranch(BSTNode * , BSTNode * );
  /// ------------------------------------------
  BSTNode * findMin() const ;
  /// ------------------------------------------
  BSTNode * findMax() const ;
  /// ------------------------------------------
  void preOrderTraversal() const ;
  void preOrderTraversal(BSTNode * node) const ;
  /// ------------------------------------------
  void inOrderTraversal() const ;
  void inOrderTraversal(BSTNode * node) const ;
  /// ------------------------------------------
  void postOrderTraversal() const ;
  void postOrderTraversal(BSTNode * node) const ;
};

//Inserts a node into the Binary Search Tree
void BST :: insert(int value) {
	//if root is null, populate it
	if (root == NULL)
	{
		root = new BSTNode(value) ;
		return ;
	}

	//if not find spot of insertion
	BSTNode *current = root ;
	while(true)
	{
		if(value == current->value)
			return;
		if(value < current->value)
		{
			if(current->left != NULL)
				current = current->left;
			else{
				current->left = new BSTNode(value);
				return ;
			}
		}
		else if(value > current->value)
		{
			if(current->right != NULL)
				current = current->right;
			else{
				current->right = new BSTNode(value);
				return ;
			}
		}
	}

}
/// ------------------------------------------

//Searches BinarySearchTree for value to remove.
//If found, it will remove the node/value and adjust the tree.
void BST :: remove(int value) {

	bool check1 = false, check2 = false ;

	if(root == NULL)
	{
		cout << "\nTree is empty.\n";
		return ; //empty
	}

	BSTNode *current = root , *parent = NULL ;

	//search tree for value.
	//if we get to null, value wasn't found
	while((current != NULL) and (value != current->value) )
	{

		if(value == current->value)
		{
			cout << value << " = " << current->value <<" ?" ;
			//done
		}
		else if (value < current->value)
		{
			parent = current ;
			current = current->left ;
		}
		else if (value > current->value)
		{
			parent = current ;
			current = current->right ;
		}
	}

	//if value not found, exit
	if (current == NULL)
		return ;

	//cases if value is found

	//trouble shooting
//		char wait ;
//		cout << "current : " << current << " current->value : " <<current->value << endl ;
//		cout << "parent : " << parent << " parent->value : " <<parent->value << endl ;
//		cin >> wait ;

		//Node is a leaf
		check1 = leaf(current, parent);
		//Node has a single branch
		check2 = singleBranch(current, parent);
		//Node has a double branch
		doubleBranch(current,parent);

		//delete target node
		if((check1)or(check2))
		{
			delete current ;
		}
}

//Test if node is a leaf and process removal
bool BST :: leaf(BSTNode *deleteNode, BSTNode *linkNode){
	bool leaf = false ;

	if ((deleteNode->left == NULL) && (deleteNode->right == NULL))
		{
			//target is a leaf
			leaf = true ;
			//Target is root
			if(deleteNode == root)
				root = NULL ;
			//target is other leaf node
			else
			{
				//unlink proper node
				if (linkNode->left == deleteNode)
				{
					linkNode->left = NULL ;
				}
				else
				{
					linkNode->right = NULL ;
				}

				//delete target node
				//delete deleteNode ;//causes program bugs
			}
		}

	return leaf;
}

//Test if node is a singleBranch and process removal
bool BST :: singleBranch(BSTNode *deleteNode, BSTNode *linkNode){
		bool singleBranch = false;

		//!A != !B has same logic as xor
		 if ( (deleteNode->left != NULL) xor (deleteNode->right != NULL) )
		{
			//Target is a singleBranch
			  singleBranch = true ;

			//Target is root
			if(deleteNode == root)
			{
				if(deleteNode->left != NULL)
					root = deleteNode->left ;
				else
					root = deleteNode->right ;
			}
			//target is other single branch node
			else
			{
				//Relink proper node
				if (linkNode->left == deleteNode)
				{
					if(deleteNode->left != NULL)
						linkNode->left = deleteNode->left ;
					else
						linkNode->left = deleteNode->right ;

				}
				else
				{
					if(deleteNode->left != NULL)
						linkNode->left = deleteNode->left ;
					else
						linkNode->left = deleteNode->right ;
				}

				//delete target node
				//delete deleteNode ;//causes program bugs
			}
		}

		 return singleBranch ;
}

//Test if node is a doubleBranch and process removal
void BST :: doubleBranch(BSTNode *replaceNode, BSTNode * linkNode){
	if((replaceNode->left != NULL) and (replaceNode->right != NULL))
	{
			//we replace current with greatest element on the left branch
			//or we can replace it with the least element on the right branch

			//we will use leftG to hold this value
			//we will do greatest on the left branch
			BSTNode * leftG = replaceNode->left ;
			BSTNode * leftGParent = replaceNode ;
			//node to the far most right is greatest
			while(leftG->right != NULL)
			{
				//linkNode = leftG ;
				leftGParent = leftG ;
				leftG = leftG->right;
			}

			//copy left greatest value to current
			replaceNode->value = leftG->value ;

			//remove and delete leftG
			leaf(leftG, leftGParent);
			singleBranch(leftG, leftGParent);

			delete leftG ;

		}
}
/// ------------------------------------------

//function finds least element in tree
BSTNode * BST :: findMin() const {
	if(root == NULL)
		return NULL ; //empty
	BSTNode *current = root ;
	//node to the far most left is least
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current ;
}
/// ------------------------------------------

//function finds greatest element in tree
BSTNode * BST :: findMax() const {
	if(root == NULL)
		return NULL ; //empty
	BSTNode *current = root ;
	//node to the far most right is greatest
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current ;
}
/// ------------------------------------------

//Prints heading, calls preOrderTraversal function, and prints endline
void BST :: preOrderTraversal() const {
cout << "preOrderTraversal: ";
preOrderTraversal(root);
cout << endl;
}

//Traverses the BinarySearchTree in preOrder and prints out the value of the nodes.
void BST :: preOrderTraversal(BSTNode * node) const {
if (node != NULL) {
  cout << node -> value << " ";
  preOrderTraversal(node -> left);
  preOrderTraversal(node -> right);
}
}
/// ------------------------------------------

//Prints heading, calls inOrderTraversal function, and prints endline
void BST :: inOrderTraversal() const {
cout << "inOrderTraversal: ";
inOrderTraversal(root);
cout << endl;
}

//Traverses the BinarySearchTree in inOrder and prints out the value of the nodes.
void BST :: inOrderTraversal(BSTNode * node) const {
if (node != NULL) {
  inOrderTraversal(node -> left);
  cout << node -> value << " ";
  inOrderTraversal(node -> right);
}
}
/// ------------------------------------------

//Prints heading, calls postOrderTraversal function, and prints endline
void BST :: postOrderTraversal() const {
cout << "postOrderTraversal: ";
postOrderTraversal(root);
cout << endl;
}

//Traverses the BinarySearchTree in postOrder and prints out the value of the nodes.
void BST :: postOrderTraversal(BSTNode * node) const {
if (node != NULL) {
  postOrderTraversal(node -> left);
  postOrderTraversal(node -> right);
  cout << node -> value << " ";
}
}

#endif /* BST_H_ */
