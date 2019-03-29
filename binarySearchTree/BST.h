/*
 * BST.h
 *
 *  Created on: Mar 27, 2019
 *      Author: ultron
 */


#ifndef BST_H_
#define BST_H_
#include "BST_NODE.h"

class BST {
private:
	BST_NODE* root;
public:
	BST(BST_NODE* root);
	void addNode(BST_NODE node);
	void deleleNode(int value);
	void printTreeOrdered() const;
	void printConnections() const;
	BST_NODE* search(int value, BST_NODE* currentNode);
	BST_NODE* getParent() const;
	BST_NODE* getChildren() const;
	int getMin() const;
	int getMax() const;
};


#endif
