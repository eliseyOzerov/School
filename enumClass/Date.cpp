/*
 * Date.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */


#include "Date.h"
#include <iostream>
#include <string>


Date::Date(int day, int month, int year) : day(day), month(month), year(year){}

std::string Date::toString()const {
	std::string res;

	res = std::to_string(this->day) +
			'.' + std::to_string(month) +
			'.' + std::to_string(year);
	return res;
}

bool Date::isEqual(const Date& second)const {
	return this->day == second.day && this->month==second.month && this->year==second.year; //ASK WHY IS THIS POSSIBLE
}
