/*
 * Event.h
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "DateTime.h"
#include <string>

class Event{
private:
	std::string name;
	std::string location;
	DateTime startTime;
	DateTime endTime;

public:
    std::string getName() const {return this->name;}
    void setName(const std::string &name) {this->name = name;}
    std::string getLocation() const {return this->location;}
    void setLocation(const std::string &loc){this->location = loc;}
    enum class Repetition{none=0, daily, weekly, monthly, yearly};
	Event(std::string name, std::string location,
			DateTime startTime, DateTime endTime);
	virtual std::string toString() const;
	virtual Repetition getRepetition() const;
	static std::string getRepetitionString(const Repetition &r);

};

#endif
