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
	void addNode(BST_NODE node) const;
	void printTreeOrdered() const;
	void printConnections() const;
	BST_NODE* search() const;
	void printParetnAndChildren();
	void deleleNode(int value);
};