/*
 * DateTime.h
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#ifndef DATETIME_H_
#define DATETIME_H_

#include "Date.h"
#include "TimeClass.h"
#include <string>

class DateTime{
private:
	Date date;
	TimeClass time;
public:
    Date& getDate(){return this->date;}
	DateTime(Date date, TimeClass time);
	DateTime(const Date &date);
	void addWeeks(int weeks);
	bool isEqual(const DateTime& dateTime) const;
	std::string toString() const;
	bool operator<(const DateTime& second);
    bool operator>(const DateTime& second);
    bool operator==(const DateTime& second);
};

#endif
