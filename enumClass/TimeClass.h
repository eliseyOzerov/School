/*
 * TimeClass.h
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#ifndef TIME_H_
#define TIME_H_

#include <string>

class TimeClass {
private:
	int hour;
	int minute;
	int second;
public:
	TimeClass(int hour, int minute, int second);
	std::string toString()const;
	int getHour()const {return this->hour;}
	int getMinute()const {return this->minute;}
	int getSecond()const {return this->second;}
	bool isEqual(const TimeClass& second)const;
	bool operator<(const TimeClass &second) const;
    bool operator>(const TimeClass &second) const;
    bool operator==(const TimeClass &second) const;
};
#endif
