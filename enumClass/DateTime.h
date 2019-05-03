/*
 * DateTime.h
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#ifndef DATETIME_H_
#define DATETIME_H_

#include "Date.h"
#include "Time.h"
#include <string>

class DateTime{
private:
	Date date;
	Time time;
public:
	DateTime(Date date, Time time);
	DateTime(const Date &date);
	bool isEqual(const DateTime& dateTime);
	std::string toString();
};

#endif
