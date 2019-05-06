//
// Created by Elisey on 06/05/2019.
//

#include "Date.h"
#include <string>

Date::Date(int day, int month, int year) : day(day), month(month), year(year){}

std::string Date::toString(){
    std::string res;

    res = std::to_string(this->day) +
          '.' + std::to_string(month) +
          '.' + std::to_string(year);
    return res;
}

bool Date::isEqual(const Date& second){
    return this->day == second.day && this->month==second.month && this->year==second.year; //ASK WHY IS THIS POSSIBLE
}

