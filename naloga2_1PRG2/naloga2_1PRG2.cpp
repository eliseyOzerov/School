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

int main(){

	vector<Clothing*> clothes;

	clothes.push_back(new Clothing());
	clothes.push_back(new Clothing());
	clothes[1]->setName("Coat");
	clothes[1]->setSize(50);
	clothes[1]->setGender(0);
	clothes.push_back(new Clothing(*clothes[1]));
	cout << "First piece of clothing: " ;
	clothes[0]->print();
	cout << "Second piece of clothing: " ;
	clothes[1]->print();
	string SCgender;
	switch(clothes[2]->getGender()){
	case 0:
		SCgender = "men";
		break;
	case 1:
		SCgender = "women";
		break;
	default:
		cout << "You fucked up bro." << endl;
	}
	cout << "Copy of second: " ;
	cout << clothes[2]->getName() << ' '
			<< SCgender << ' '
			<< to_string(clothes[2]->getSize()) <<' '
			<< fixed << setprecision(2) << clothes[2]->getPrice() << "\u20AC "
			<< to_string(clothes[2]->getQuantity())<< endl;

	clothes.push_back(new Clothing(1, 38, 50.0, 1, "Blouse"));

	cout << "Print the whole shopping list: " << endl;
	clothingToString(clothes);
	cout << endl;
	cout << "Total price: " << fixed << setprecision(2) << getClothingTotal(clothes) << "\u20AC" << endl;
	delete clothes[0];
	delete clothes[1];
	delete clothes[2];
	delete clothes[3];
}


