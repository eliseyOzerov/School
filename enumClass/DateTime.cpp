/*
 * DateTime.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#include "DateTime.h"
#include "Calendar.h"
#include <string>

DateTime::DateTime(Date date, TimeClass time): date(date), time(time){}

DateTime::DateTime(const Date &date) : date(date), time(0,0,0){}
std::string DateTime::toString() const{
	std::string res;
	res = this->date.toString() + ' ' + this->time.toString();
	return res;

}

bool DateTime::isEqual(const DateTime& dt) const{
	return this->date.isEqual(dt.date) && this->time.isEqual(dt.time);
}

void DateTime::addWeeks(int weeks) {
    for(int i = 0; i < 7*weeks; i++){
        ++this->date;
    }
}

bool DateTime::operator<(const DateTime &second) {
    if(this->date < second.date){
        return true;
    } else if(this->date == second.date) {
        return this->time < second.time;
    } else return false;
}

bool DateTime::operator>(const DateTime &second) {
    if(this->date > second.date){
        return true;
    } else if(this->date == second.date){
        return this->time > second.time;
    } else return false;
}

bool DateTime::operator==(const DateTime &second) {
    return this->date == second.date && this->time == second.time;
}


