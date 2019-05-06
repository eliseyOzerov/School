//
// Created by Elisey on 05/05/2019.
//

#include "DLL.h"

DLL::DLL() {}
DLL::DLL(Node *head): HEAD(head) {}
DLL::~DLL(){
    purgeList();
    delete this->HEAD;
}

void DLL::purgeList(){
    Node* current = this->HEAD;
    while(current->getNext() != nullptr){
        Node* tmp = current;
        current = current->getNext();
        tmp->setNext(nullptr);
        tmp->setPrev(nullptr);
        delete tmp;
    }
    this->HEAD->setNext(nullptr);
    this->HEAD->setPrev(nullptr);
    this->setTail(this->HEAD);
}
void DLL::printList(){
    Node* current = this->HEAD;
    while(current != nullptr){
        std::cout << std::to_string(current->getValue()) << ' ';
        current = current->getNext();
    }
    std::cout << std::endl;
}

Node* DLL::addNode(int val) {
    Node* n = new Node(val);
    n->setPrev(this->TAIL);
    this->TAIL->setNext(n);
    this->setTail(n);
    return n;
}

void DLL::generateRandomSequence(int size){
    purgeList();
    this->HEAD->setValue(rand()%1001);
    for(int i = 0; i < size; i++){
        addNode(rand()%1001);
    }
}

void DLL::generateIncreasingSequence(int size) {
    purgeList();
    this->HEAD->setValue(0);
    for(int i = 1; i < size; i++){
        addNode(i);
    }
}

int DLL::sum(){
    Node* current = this->HEAD;
    int sum = 0;
    while(current != nullptr){
        sum+=current->getValue();
        current = current->getNext();
    }
    return sum;
}

bool DLL::sorted(){
    Node* current = this->HEAD;
    while(current != nullptr){
        if(current->getNext() && current->getNext()->getValue() < current->getValue()){
            return false;
        }
        current = current->getNext();
    }
    return true;
}

void DLL::swapValues(Node* i, Node* k){
    int tmp = k->getValue();
    k->setValue(i->getValue());
    i->setValue(tmp);
}

Node* DLL::deli(Node* dno, Node* vrh){

    int pivot = dno->getValue();
    Node* dn = dno;
    Node* vr = vrh;
    bool crossed = false;
    while(!crossed){
        while(dn->getValue() <= pivot && dn != vrh){
            if(vr==dn)crossed=true;
            dn = dn->getNext();
        }
        while(vr->getValue() >= pivot && vr != dno){
            if(vr==dn)crossed=true;
            vr = vr->getPrev();
        }
        if(vr==dn)crossed=true;
        if(!crossed){
            swapValues(vr, dn);
        }
    }
    swapValues(dno, vr);
    return vr;
}

void DLL::quickSort(Node* dno, Node* vrh){
    if(dno != vrh){
        Node* j = deli(dno, vrh);
        if(j!=dno){
            quickSort(dno, j->getPrev());
        }
        if(j!=vrh){
            quickSort(j->getNext(), vrh);
        }

    }
}