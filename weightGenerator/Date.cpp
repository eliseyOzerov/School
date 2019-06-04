//
// Created by Elisey on 03/06/2019.
//

#include <sstream>
#include "Date.h"

Date Date::operator+(int num) {
    Date d = *this;
    d.day += num;
    if(d.day > Date::months[d.month-1]) {
        d.month++;
        d.day = 1;
        if (d.month > 12) {
            d.year++;
            d.month = 1;
        }
    }
    return d;
}



bool Date::isEqual(const Date &second) const {
    return this->day == second.day && this->month == second.month && this->year == second.year;
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << this->day << '.' << this->month << '.' << this->year;
    return ss.str();
}
