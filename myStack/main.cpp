#include <iostream>
#include "MyStack.h"

int main() {
    MyStack<int> i;
    MyStack<Date> d;
    i.push(10);
    i.push(20);
    i.push(30);
    i.push(40);
    i.pushX(std::vector<int>{22,33,44,55});
    i.reverse();
    std::cout << i.toString();
    std::vector<int> m = i.backX(3);
    for(int n : m){
        std::cout << n << ' ';
    }

    i.popX(3);
    std::cout << i.toString();
    MyStack<int>* n = i.split(3);
    std::cout << n->toString();
    d.push(Date(10, 7, 2017));
    d.push(Date(20, 5, 2011));
    std::cout << d.toString();
    return 0;
}