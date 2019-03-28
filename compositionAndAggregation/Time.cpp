/*
 * Time.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#include "Time.h"
#include <iostream>
#include <string>

Time::Time(int hour, int minute, int second): hour(hour), minute(minute), second(second){}

std::string Time::toString(){
	std::string res;
	std::string hour = "";
	std::string minute = "";
	std::string second = "";
	if(std::to_string(this->hour).length()<2){
		hour += "0";
	}

	if(std::to_string(this->minute).length()<2){
		minute += "0";
	}

	if(std::to_string(this->second).length()<2){
		second += "0";
	}

	hour+=std::to_string(this->hour);
	minute+=std::to_string(this->minute);
	second+=std::to_string(this->second);

	res = hour + ':' + minute + ':' + second;
	return res;
}

bool Time::isEqual(const Time& second){
	return this->hour == second.hour && this->minute==second.minute && this->second==second.second; //ASK WHY IS THIS POSSIBLE
}
