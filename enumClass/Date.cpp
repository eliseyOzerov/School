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

Date& Date::operator++(){
    this->day++;
    if(this->day > this->months[this->month-1]) {
        this->month++;
        this->day = 1;
        if (this->month > 12) {
            this->year++;
            this->month = 1;
        }
    }
    return *this;
}

const Date Date::operator++(int) {
    Date* res = this;
    ++(*this);
    return *res;
}

bool Date::isAfter(const Date &second){
    if(second.getYear() > this->getYear()) {
        return false;
    }
    if(second.getMonth() > this->getMonth()){
        return false;
    }

    return second.getDay() < this->getDay();

}

bool Date::operator<(const Date &d) {
    if(d.getYear() < this->getYear()) {
        return false;
    }
    if(d.getMonth() < this->getMonth()){
        return false;
    }

    return d.getDay() > this->getDay();
}

bool Date::operator>(const Date &d) {
    if(d.getYear() > this->getYear()) {
        return false;
    }
    if(d.getMonth() > this->getMonth()){
        return false;
    }

    return d.getDay() < this->getDay();
}

bool Date::operator==(const Date &d) {
    return this->getDay() == d.getDay() && this->getMonth() == d.getMonth() && this->getYear() == d.getYear();
}


