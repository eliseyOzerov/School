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
	BST_NODE* root = nullptr;
	void substituteForMaxOfLeftSubtree(BST_NODE* node);
	void substituteForMinOfRightSubtree(BST_NODE* node);
public:
	BST(BST_NODE* root);
	BST();
	void addMovie(int value, std::string data);
	void addMoviesFromFile(std::string path);
	void deleteNode(int value);
	void deleteTree(BST_NODE* root);
	void printTreeOrdered(BST_NODE* node) const;
	void printConnections(BST_NODE* node) const;
	void printParentAndChildren(int value);
	BST_NODE* search(int value, BST_NODE* pRoot);
	BST_NODE* getMin(BST_NODE* pNode) const;
	BST_NODE* getMax(BST_NODE* pNode) const;
	BST_NODE* getRoot() const;
	void setRoot(BST_NODE* node);
};


#endif
