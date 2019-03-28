/*
 * Date.h
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */
#ifndef DATE_H_
#define DATE_H_

#include <string>

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);
	std::string toString();
	int getDay(){return this->day;}
	int getMonth(){return this->month;}
	int getYear(){return this->year;}
	bool isEqual(const Date& second);
};

#endif
