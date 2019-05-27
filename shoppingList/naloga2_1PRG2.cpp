/*
 * naloga2_1PRG2.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: ultron
 *
 *      https://stackoverflow.com/questions/21204589/static-vs-instance-variables-difference
 *      http://heather.cs.ucdavis.edu/~matloff/classvars.html
 */

#include "Clothing.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void clothingToString(vector<Clothing*> clothes){
	for(unsigned int i = 0; i<clothes.size(); i++){
		clothes[i]->print();
	}
}

double getClothingTotal(vector<Clothing*> clothes){
	double final = 0;
	for(unsigned int i = 0; i<clothes.size(); i++){
			final += clothes[i]->getTotalPrice();
		}

	return final;
}

void addClothing(std::vector<Clothing*> &shop, int gender, int size, std::string name, double price) {
    Clothing* c = new Clothing(gender, size, price, 0, name);
    if(!c->isSizeValid()) throw WrongClothingSize(std::to_string(c->getSize()));
    if(c->getPrice() < 0) throw InvalidPrice(std::to_string(c->getPrice()));
    shop.emplace_back(c);
}

int main(){

	std::vector<Clothing*> clothes;
	try{
        addClothing(clothes, 0, 98, "Clothing1", -10);
	} catch(exception &e){
	    std::cout << e.what();
	}
    try{
        addClothing(clothes, 1 , 46, "Clothing3", -10);
    } catch(exception &e){
        std::cout << e.what();
    }
    try{
        addClothing(clothes, 1, 46, "Clothing2", 200);
    } catch(exception &e){
        std::cout << e.what();
    }
    try{
        addClothing(clothes, 0, 46, "Clothing4", 50);
    } catch(exception &e){
        std::cout << e.what();
    }
    std::for_each(clothes.begin(), clothes.end(), [](Clothing* c){
       if(!c->getGender()) std::cout << c->toString() << '\n';
    });


}


