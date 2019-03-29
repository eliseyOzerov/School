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

class BST_NODE {
private:
	int value;
	BST_NODE* parent = nullptr;
	BST_NODE* leftChild = nullptr;
	BST_NODE* rightChild = nullptr;
public:
	BST_NODE(int value) :
			value(value) {
	}

	void printNode() const {
		std::cout << std::to_string(this->value) << ' ';
	}

	int getValue() const {
		return value;
	}

	void setValue(int value) {
		this->value = value;
	}

	BST_NODE* getLeftChild() const {
		return leftChild;
	}

	void setLeftChild(const BST_NODE*& leftChild = nullptr) {
		this->leftChild = leftChild;
	}

	const BST_NODE*& getParent() const {
		return parent;
	}

	void setParent(const BST_NODE*& parent = nullptr) {
		this->parent = parent;
	}

	const BST_NODE*& getRightChild() const {
		return rightChild;
	}

	void setRightChild(const BST_NODE*& rightChild = nullptr) {
		this->rightChild = rightChild;
	}
};

#endif
