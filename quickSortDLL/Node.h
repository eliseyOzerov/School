//
// Created by Elisey on 05/05/2019.
//

#ifndef QUICKSORTDLL_NODE_H
#define QUICKSORTDLL_NODE_H


class Node{
private:
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;
public:
    Node();
    Node(int value);
    ~Node();
    int getValue(){return this->value;}
    void setValue(int value){this->value = value;}
    Node* getPrev(){return this->prev;}
    void setPrev(Node* prev){this->prev = prev;}
    Node* getNext(){return this->next;}
    void setNext(Node* next){this->next = next;}
};


#endif //QUICKSORTDLL_NODE_H
