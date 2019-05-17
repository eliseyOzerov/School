/*
 * Time.h
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#ifndef TIME_H_
#define TIME_H_

#include <string>

class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time(int hour, int minute, int second);
	std::string toString()const;
	int getHour()const {return this->hour;}
	int getMinute()const {return this->minute;}
	int getSecond()const {return this->second;}
	bool isEqual(const Time& second)const;
};
#endif
