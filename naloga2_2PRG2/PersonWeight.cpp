/*
 * PersonWeight.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: ultron
 */


#include "PersonWeight.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

PersonWeight::PersonWeight() : month(1), day(1), weight(80.0){}

PersonWeight::PersonWeight(const PersonWeight& pw) :
		month(pw.weight), day(pw.day), weight(pw.weight){}

PersonWeight::PersonWeight(int month, int day, double weight) :
		month(month), day(day), weight(weight){}

PersonWeight::~PersonWeight(){}

void PersonWeight::setMonth(int month){
	if(month >= 1 && month <= 12){
		this->month = month;
	} else {
		std::cout << "Month invalid." << std::endl;
	}
}

void PersonWeight::setDay(int day){
	if(day >= 1 && day <= 31){
		this->day = day;
	} else {
		std::cout << "Day invalid." << std::endl;
	}
}

void PersonWeight::setWeight(double weight){
	if(weight){
		this->weight = weight;
	} else {
		std::cout << "Weight invalid." << std::endl;
	}
}

int PersonWeight::getMonth(){
	return this->month;
}

int PersonWeight::getDay(){
	return this->day;
}

double PersonWeight::getWeight(){
	return this->weight;
}

std::string PersonWeight::toString(){
	std::stringstream s;
	s << std::fixed << std::setprecision(1) << this->weight;
	std::string weight = s.str();
	std::string res = std::to_string(this->day) + '.' + std::to_string(this->month) + "   " + weight + "kg" + '\n';
	return res;
}

bool PersonWeight::isFirst(int day){
	if(day == 1){
		return true;
	} else {
		return false;
	}
}

bool PersonWeight::isJanuary(int month){
	if(month == 1){
			return true;
		} else {
			return false;
		}
}
