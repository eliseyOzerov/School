/*
 * Calendar.h
 *
 *  Created on: Mar 25, 2019
 *      Author: ultron
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "Event.h"
#include <string>
#include <vector>

class Calendar{
private:
	std::string name;
	std::vector<Event*> events;
public:
	Calendar(std::string name);
	std::string toString() const;
	void addEvent(Event* event);
};


#endif