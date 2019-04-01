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
BST::BST(){}

BST_NODE* BST::search(int value, BST_NODE* pRoot){
	if(pRoot == nullptr || pRoot->getValue() == value){
		return pRoot;
	} else {
		if(pRoot->getValue() < value){
			return this->search(value, pRoot->getRightChild());
		} else {
		    return this->search(value, pRoot->getLeftChild());
		}
	}
}

void BST::addNode(BST_NODE* nodeToAdd) {
    BST_NODE* tmp = nullptr;
    BST_NODE* pRoot = this->root;
    //if root is empty, set node as root and its parent to nullptr
    if(this->root == nullptr){
        this->root = nodeToAdd;
        this->root->setParent(tmp);
        return;
    }
    while(pRoot != nullptr){
        tmp = pRoot;
        if(nodeToAdd->getValue() < pRoot->getValue()){
            pRoot = pRoot->getLeftChild();
        } else if(nodeToAdd->getValue() > pRoot->getValue()){
            pRoot = pRoot->getRightChild();
        } else {
            std::cout << "Node already exists." << std::endl;
            return;
        }
    }
    nodeToAdd->setParent(tmp);
    if(tmp==nullptr){
        pRoot = nodeToAdd;
    } else {
        if(nodeToAdd->getValue() < tmp->getValue()){
            tmp->setLeftChild(nodeToAdd);
        } else {
            tmp->setRightChild(nodeToAdd);
        }
    }

}

void BST::substituteForMaxOfLeftSubtree(BST_NODE* pNode){
    BST_NODE* substitute = this->getMax(pNode->getLeftChild());
    BST_NODE* pSubParent = substitute->getParent();
    BST_NODE* pSubLeftChild = substitute->getLeftChild();
    BST_NODE* pNodeParent = pNode->getParent();
    BST_NODE* pNodeLeftChild = pNode->getLeftChild();
    BST_NODE* pNodeRightChild = pNode->getRightChild();

    /*Disconnect substitute from its parent and connect left child of substitute to it instead.
     * If left child is null, pSubParent.rightChild will be a nullptr. If not, it will
     * point to actual left child of substitute.
     */
    pSubParent->setRightChild(pSubLeftChild);

    //If substitute has left child, we have to set its parent to pSubParent to connect.
    if(pSubLeftChild != nullptr){
        pSubLeftChild->setParent(pSubParent);
    }

    //Connect substitute to to-be deleted node's parent.
    substitute->setParent(pNodeParent);
    if(pNodeParent!= nullptr){
        if(pNode->getValue() < pNodeParent->getValue()){
            pNodeParent->setLeftChild(substitute);
        } else {
            pNodeParent->setRightChild(substitute);
        }
    } else {
        this->root = substitute;
    }

    /*Connect left child of to-be deleted node to substitute. We know it exists
     * because we called this function based on that fact. We do it unless left child IS the
     * substitute.
     */
    if(pNodeLeftChild!=substitute){
        pNodeLeftChild->setParent(substitute);
        substitute->setLeftChild(pNodeLeftChild);
    }

    //Do the same for the right child if it exists
    if(pNodeRightChild!=nullptr){
        pNodeRightChild->setParent(substitute);
        substitute->setRightChild(pNodeRightChild);
    }
}

void BST::substituteForMinOfRightSubtree(BST_NODE* pNode){
    BST_NODE* substitute = this->getMin(pNode->getRightChild());
    BST_NODE* pSubParent = substitute->getParent();
    BST_NODE* pSubRightChild = substitute->getRightChild();
    BST_NODE* pNodeParent = pNode->getParent();
    BST_NODE* pNodeLeftChild = pNode->getLeftChild();
    BST_NODE* pNodeRightChild = pNode->getRightChild();

    /*Disconnect substitute from its parent and connect right child of substitute to it instead.
     * If right child is null, pSubParent.leftChild will be a nullptr. If not, it will
     * point to actual right child of substitute.
     */
    pSubParent->setLeftChild(pSubRightChild);

    //If substitute has right child, we have to set its parent to pSubParent to connect.
    if(pSubRightChild != nullptr){
        pSubRightChild->setParent(pSubParent);
    }

    //Connect substitute to to-be deleted node's parent.
    substitute->setParent(pNodeParent);
    if(pNodeParent!= nullptr){
        if(pNode->getValue() < pNodeParent->getValue()){
            pNodeParent->setLeftChild(substitute);
        } else {
            pNodeParent->setRightChild(substitute);
        }
    } else {
        this->root = substitute;
    }

    /*Connect right child of to-be deleted node to substitute. We know it exists
     * because we called this function based on that fact. We do it unless right child IS the
     * substitute.
     */
    if(pNodeRightChild!=substitute){
        pNodeRightChild->setParent(substitute);
        substitute->setRightChild(pNodeLeftChild);
    }


    //Do the same for the left child if it exists
    if(pNodeLeftChild!= nullptr){
        pNodeLeftChild->setParent(substitute);
        substitute->setLeftChild(pNodeLeftChild);
    }
}


void BST::deleteNode(int value) {
    BST_NODE* pNode = search(value, this->root);
    if(pNode == nullptr){
        std::cout << "Node doesn't exist." << std::endl;
    } else {
        BST_NODE* pNodeParent = pNode->getParent();
        BST_NODE *pNodeLeftChild = pNode->getLeftChild();
        BST_NODE *pNodeRightChild = pNode->getRightChild();

        if (pNodeLeftChild != nullptr) {
            substituteForMaxOfLeftSubtree(pNode);
        } else if (pNodeRightChild != nullptr) {
            substituteForMinOfRightSubtree(pNode);
        } else {
            /*pNodeLeftChild and pNodeRightChild used for convenience as it throws an error
             * when trying to pass a nullptr as parameter
             */
            if(pNode->getValue()<pNodeParent->getValue()){
                pNodeParent->setLeftChild(pNodeLeftChild);
            } else {
                pNodeParent->setRightChild(pNodeRightChild);
            }
        }
    }
    delete pNode;
}

void BST::printTreeOrdered(BST_NODE* root) const {
    if(root!= nullptr){
        printTreeOrdered(root->getLeftChild());
        std::cout << std::to_string(root->getValue()) << ' ';
        printTreeOrdered(root->getRightChild());
    }
}

void BST::printConnections(BST_NODE* node) const {
    if(node!=nullptr){
        if(node->getLeftChild()!=nullptr){
            std::cout<< node->getValue() << " -> " << node->getLeftChild()->getValue() << std::endl;
            printConnections(node->getLeftChild());
        }
        if (node->getRightChild() != nullptr){
            std::cout << node->getValue() << " -> " << node->getRightChild()->getValue() << std::endl;
            printConnections(node->getRightChild());
        }
    } else {
        std::cout << "BST empty." << std::endl;
    }

}

void BST::printParentAndChildren(int value) {
    BST_NODE* root = this->root;
    BST_NODE* node = this->search(value, root);
    std::cout << "Predhodnik: ";
    if(node->getParent()!= nullptr){
        std::cout << node->getParent()->getValue();
    } else {
        std::cout << "ne obstaja";
    }
    std::cout << " Levi naslednik: ";
    if(node->getLeftChild()!= nullptr){
        std::cout << node->getLeftChild()->getValue();
    } else {
        std::cout << "ne obstaja";
    }
    std::cout << " Desni naslednik: ";
    if(node->getRightChild()!= nullptr){
        std::cout << node->getRightChild()->getValue();
    } else {
        std::cout << "ne obstaja";
    }
    std::cout << std::endl;

}

BST_NODE* BST::getMin(BST_NODE* pNode) const {
    if(pNode!= nullptr){
        if(pNode->getLeftChild() == nullptr){
            return pNode;
        } else {
            return this->getMin(pNode->getLeftChild());
        }
    }
}

BST_NODE* BST::getMax(BST_NODE* pNode) const {
    if(pNode != nullptr){
        if(pNode->getRightChild() == nullptr){
            return pNode;
        } else {
            return this->getMax(pNode->getRightChild());
        }
    }
}

BST_NODE* BST::getRoot() const {
    return this->root;
}

void BST::setRoot(BST_NODE* node){
    this->root = node;
}
