/*
 * DateTime.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#include "DateTime.h"
#include <string>

DateTime::DateTime(Date date, Time time): date(date), time(time){}

std::string DateTime::toString(){
	std::string res;

	res = this->date.toString() + ' ' + this->time.toString();
	return res;

}

bool DateTime::isEqual(const DateTime& dt){
	return this->date.isEqual(dt.date) && this->time.isEqual(dt.time);
}

