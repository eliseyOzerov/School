//
// Created by Elisey on 06/05/2019.
//

#ifndef MYSTACK_MYSTACK_H
#define MYSTACK_MYSTACK_H
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include "Date.h"

template<typename T>
class MyStack{
private:
    std::vector<T> vec;
    std::string name;
public:
    MyStack();
    ~MyStack();
    MyStack<T>* split(const int& n);
    void swap(T* a, T* b);
    bool empty();
    int size();
    T back();
    void push(const T t);
    T pop();
    std::string toString();
    void popX(int n);
    std::vector<T> backX(const int n);
    void pushX(const std::vector<T> v);
    void reverse();
    void randomize();
};

template <typename T>
MyStack<T>::MyStack(){}

template<typename T>
MyStack<T>::~MyStack(){}

template<> MyStack<Date>::MyStack(){}

template<> MyStack<Date>::~MyStack(){}

template<typename T>
void MyStack<T>::swap(T* a, T* b){
    T t = *b;
    *b = *a;
    *a = t;
}

template<typename T>
MyStack<T>* MyStack<T>::split(const int& n){
    MyStack* res = new MyStack();
    if(n > this->vec.size()){
        std::cout << "Vector too small.\n";
        return nullptr;
    }
    for(int i = 0; i < n; i++){
        res->push(this->vec[i]);
    }
    return res;
}

template<typename T>
bool MyStack<T>::empty(){
    return !vec.size();
}

template<typename T>
int MyStack<T>::size(){
    return vec.size();
}
template<typename T>
T MyStack<T>::back(){
    return vec.back();
}

template<typename T>
void MyStack<T>::push(const T t){
    vec.push_back(t);
}
template<typename T>
T MyStack<T>::pop(){
    T t = vec.back();
    vec.pop_back();
    return t;
}
template<typename T>
std::string MyStack<T>::toString(){
    std::string res = "";
    for(T t : vec){
        res += std::to_string(t) + ' ';
    }
    res += '\n';
    return res;
}

template<> std::string MyStack<Date>::toString(){
    std::string res;
    for(Date t : vec){
        res += t.toString() + ' ';
    }
    res += '\n';
    return res;
}

template<typename T>
void MyStack<T>::popX(const int n){
    for(int i = 0; i < n; i++){
        vec.pop_back();
    }
}
template<typename T>
std::vector<T> MyStack<T>::backX(const int n){
    std::vector<T> v;
    for(int i = this->vec.size()-n; i < this->vec.size(); i++){
        v.push_back(this->vec[i]);
    }
    return v;
}
template<typename T>
void MyStack<T>::pushX(const std::vector<T> v){
    for(T t : v){
        this->vec.push_back(t);
    }
}

template<typename T>
void MyStack<T>::reverse(){
    int i = 0;
    int j = vec.size()-1;
    while(i<=j){
        swap(&vec.at(i), &vec.at(j));
        i++;
        j--;
    }
}

template<typename T>
void MyStack<T>::randomize(){
    for(int i = 0; i<vec.size(); i++){
        swap(&vec.at(i), &vec.at(rand()%vec.size()));
    }
}
#endif //MYSTACK_MYSTACK_H
