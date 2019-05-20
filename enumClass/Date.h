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
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
	Date(int day, int month, int year);
	std::string toString()const ;
	int getDay()const {return this->day;}
	int getMonth()const {return this->month;}
	int getYear()const {return this->year;}
	bool isEqual(const Date& second)const ;
    bool isAfter(const Date &second);
	Date& operator++();
	const Date operator++(int);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator==(const Date& d);
};

#endif
