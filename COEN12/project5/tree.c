//Josh Yi
//Project 5
//Dr. Atkinson
//5/20/14
//Tues. 2:15

//This c file is a binary tree abstract data type using parent pointers as well as pointers to two children. 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
};

//O(1)
//detach the right or left child
void detach(struct tree *child) {
	if(child->parent!=NULL) {
		if(child->parent->left==NULL) {
			 child->parent->left=NULL;
		}
		else {
			child->parent->right=NULL;
		}
	}
}

//O(1)
//return a pointer to a new tree with the specified left and right subtrees and data for its root
struct tree *createTree(int data, struct tree *left, struct tree *right) {
	struct tree *root;
	root=malloc(sizeof(struct tree));
	assert(root!=NULL);
	root->data=data;
	root->right=right;
	root->left=left;
	root->parent=NULL;
	if(left!=NULL) {
		detach(left);
		root->left->parent=root;
	}
	if(right!=NULL) {
		detach(right);
		root->right->parent=root;
	}
	return root;
}

//O(n)
//deallocating memory for the entire subtree pointed to by root
void destroyTree(struct tree *root) {
	if(root==NULL) {
		return;
	}
	destroyTree(root->left);
	destroyTree(root->right);
	free(root);
}

//O(1)
//return the data in the root of the subtree pointed to by root
int getData(struct tree *root) {
	assert(root!=NULL);
	return root->data;	
}

//O(1)
//return the left subtree of the subtree pointed to by root
struct tree *getLeft(struct tree *root) {
	assert(root!=NULL);
	return root->left;
}

//O(1)
//return the right subtree of the subtree pointed to by root
struct tree *getRight(struct tree *root) {
	assert(root!=NULL);
	return root->right;
}

//O(1)
//return the parent tree of the subtree pointed to by root
struct tree *getParent(struct tree *root) {
	assert(root!=NULL);
	return root->parent;
}

//O(1)
//update the left subtree of root
void setLeft(struct tree *root, struct tree *left) {
	assert(root!=NULL);
	detach(left);
	root->left=left;
	root->left->parent=root;
}

//O(1)
//update the right subtree of root
void setRight(struct tree *root, struct tree *right) {
	assert(root!=NULL);
	detach(right);
	root->right=right;
	root->right->parent=root;
}
