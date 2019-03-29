/*
 * BST.cpp
 *
 *  Created on: Mar 27, 2019
 *      Author: ultron
 */

#include "BST.h"
#include "BST_NODE.h"
#include <iostream>
#include <string>

BST::BST(BST_NODE* node) : root(node){}

BST_NODE* BST::search(int value, BST_NODE* currentNode){
	if(currentNode == nullptr || currentNode->getValue() == value){
		return currentNode;
	} else {
		if(currentNode->getValue() > value){
			return this->search(value, currentNode->getRightChild());
		}
	}
}

void BST::addNode(BST_NODE node) {
}

void BST::deleleNode(int value) {
}

void BST::printTreeOrdered() const {
}

void BST::printConnections() const {
}

BST_NODE* BST::getParent() const {
}

BST_NODE* BST::getChildren() const {
}

int BST::getMin() const {
}

int BST::getMax() const {
}
