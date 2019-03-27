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
	Event(std::string name, std::string location,
			DateTime startTime, DateTime endTime);
	virtual std::string toString();
};

#endif
