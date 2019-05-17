/*
 * Calendar.h
 *
 *  Created on: Mar 25, 2019
 *      Author: ultron
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "Event.h"
#include "LectureEvent.h"
#include "BirthdayEvent.h"
#include "MeetingEvent.h"
#include <string>
#include <map>
#include <vector>

class Calendar{
private:
	std::string name;
	std::map<std::string, Event*> events;
public:
    std::map<std::string, Event*> getEvents() const {return this->events;}
	Calendar(std::string name);
	std::string toString() const;
	bool addEvent(Event* event);
	Event* findEvent(const std::string &name) const;
	bool deleteEvent(const std::string &name);
	int numOfEvents() const {return this->events.size();}
	static std::vector<Event*> toVector(Calendar* cal);
	bool isEmpty(){return events.empty();}
	int purgeCal(){this->events.clear();}
	int count(const std::string &s){return events.count(s);}
};


#endif
