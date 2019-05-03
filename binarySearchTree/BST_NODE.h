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
#include <list>

class BST_NODE {
private:
	int value;
	std::list<std::string> data;
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

	void addData(std::string string){
	    data.push_front(string);
	}

	std::list<std::string> getData(){
	    return data;
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

	void setLeftChild(BST_NODE*& leftChild) {
		this->leftChild = leftChild;
	}

	BST_NODE* getParent() const{
		return parent;
	}

	void setParent(BST_NODE*& parent) {
		this->parent = parent;
	}

	BST_NODE* getRightChild() const{
		return rightChild;
	}

	void setRightChild(BST_NODE*& rightChild) {
		this->rightChild = rightChild;
	}
};

#endif
