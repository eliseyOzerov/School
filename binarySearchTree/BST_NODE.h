/*
 * BST_NODE.h
 *
 *  Created on: Mar 27, 2019
 *      Author: ultron
 */



#ifndef BST_NODE_H_
#define BST_NODE_H_
#include <iostream>
#include <string>

class BST_NODE{
private:
	int value;
	BST_NODE* parent = nullptr;
	BST_NODE* leftChild = nullptr;
	BST_NODE* rightChild = nullptr;
public:
	BST_NODE(int value);
	void setValue(int value){this-value = value;}
	int getValue(){return this->value;}
	void printNode(){std::cout << std::to_string(this->value) << ' ';};
};

#endif
