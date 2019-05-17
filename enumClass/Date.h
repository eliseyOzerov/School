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
	std::string toString()const ;
	int getDay()const {return this->day;}
	int getMonth()const {return this->month;}
	int getYear()const {return this->year;}
	bool isEqual(const Date& second)const ;
};

#endif
