/*
 * DateTime.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#include "DateTime.h"
#include <string>

DateTime::DateTime(Date date, Time time): date(date), time(time){}

DateTime::DateTime(const Date &date) : date(date), time(0,0,0){}
std::string DateTime::toString() const{
	std::string res;

	res = this->date.toString() + ' ' + this->time.toString();
	return res;

}

bool DateTime::isEqual(const DateTime& dt) const{
	return this->date.isEqual(dt.date) && this->time.isEqual(dt.time);
}


