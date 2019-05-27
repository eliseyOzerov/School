/*
 * Clothing.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: ultron
 */

#include "Clothing.h"
#include "WrongClothingSize.h"
#include "InvalidPrice.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

double Clothing::discount = 0.2;
int Clothing::count = 0;
Clothing::Clothing() : gender(0), size(50), price(50.0), quantity(1), name("Shirt"){}

Clothing::Clothing(const Clothing& clothing) :
		gender(clothing.gender),
		size(clothing.size),
		price(clothing.price),
		quantity(clothing.quantity),
		name(clothing.name){}

Clothing::Clothing(int gender, int size, double price, int quantity, std::string name) :
		gender(gender),
		size(size),
		price(price),
		quantity(quantity),
		name(name){
    if(!this->isSizeValid())throw WrongClothingSize(std::to_string(this->size));
    if(this->price < 0) throw InvalidPrice(std::to_string(this->price));
}

Clothing::~Clothing(){}

void Clothing::setGender(int gender){
	if(gender != 0 && gender != 1){
		std::cout << "Gender invalid.";
		return;
	}
	this->gender = gender;
}

void Clothing::setSize(int size){
    if(!this->isSizeValid())throw WrongClothingSize(std::to_string(this->size));
    this->size = size;
}

void Clothing::setName(std::string name){
	this->name = name;
}

void Clothing::setPrice(double price){
    if(this->price < 0) throw InvalidPrice(std::to_string(this->price));
	this->price = price;
}

void Clothing::setQuantity(int quantity){
	if(quantity>-1){
		this->quantity = quantity;
	} else {
		std::cout << "Invalid value." << std::endl;
	}

}



void Clothing::print(){
	std::cout << this->toString() << std::endl;
}

double Clothing::getTotalPrice(){
	return this->price * this->quantity * (1-discount);
}


std::string Clothing::toString(){
	std::string gender;
	if(this->gender){
		gender = "women";
	} else {
		gender = "men";
	}
	double price = this->price * (1-discount);
	std::stringstream ss;

	ss<< this->name << ' ' << gender << ' ' << std::to_string(this->size) << ' ';
	ss<< std::fixed << std::setprecision(2) << price ;
	ss<< "\u20AC" << ' ' << std::to_string(this->quantity);
	return ss.str();
}

bool Clothing::isSizeValid() {
    int size = this->size;
    if(!gender){
        return size<=56 && size>=46 && size % 2 == 0;
    } else {
        return size<=54 && size>=32 && size % 2 == 0;
    }
}



void Clothing::addFromFile(std::string fileName) {

}





