//
// Created by Elisey on 05/05/2019.
//

#ifndef QUICKSORTDLL_DLL_H
#define QUICKSORTDLL_DLL_H
#include "Node.h"
#include <iostream>

class DLL{
private:
    Node* HEAD = new Node();
    Node* TAIL = HEAD;
    bool filled = false;
public:
    DLL();
    DLL(Node* head);
    ~DLL();
    Node* getHead(){ return this->HEAD;}
    void setHead(Node* head){this->HEAD = head;}
    Node* getTail(){return this->TAIL;}
    void setTail(Node* tail){this->TAIL = tail;}
    Node* addNode(int val);
    void purgeList();
    void printList();
    void generateRandomSequence(int size);
    void generateIncreasingSequence(int size);
    bool sorted();
    void swapValues(Node* i, Node* k);
    Node* deli(Node* dno, Node* vrh);
    void quickSort(Node* dno, Node* vrh);
    int sum();
    void setFilled(bool b){this->filled = b;}
    bool getFilled(){return this->filled;}

};


#endif //QUICKSORTDLL_DLL_H
