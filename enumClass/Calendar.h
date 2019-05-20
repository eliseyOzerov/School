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
#include <algorithm>
#include <time.h>
#include <chrono>

class Calendar{
private:
	std::string name;
	std::map<std::string, Event*> events;
	std::vector<Event*> eventsVec;
public:
    std::map<std::string, Event*> getEvents() const {return this->events;}
	Calendar(std::string name);
	std::string toString() const;
	bool addEvent(Event* event);
    int numOfEvents() const {return this->events.size();}

	Event* findEvent(const std::string &name) const;
	bool deleteEvent(const std::string &name);
    std::vector<Event*> toVector();
	bool isEmpty(){return events.empty();}
	int purgeCal(){this->events.clear();}
	int count(const std::string &s){return events.count(s);}

	//naloga 10.1
    void sort(bool (*c)(Event*, Event*));
	friend bool ascendingDates(Event* i, Event* j);
    friend bool descendingDates(Event* i, Event* j);
    friend bool ascendingNames(Event* i, Event* j);
    Event* find(bool (*c)(Event*));

    //std::cout<<calendar->find(isAfterCurrentTime)->toString();

    //naloga 9.1
    bool operator<(const Calendar& cal);
	bool operator>(const Calendar& cal);
	bool operator==(const Calendar& cal);
    Calendar& operator++();
    friend std::ostream& operator << (std::ostream &out, const Calendar &cal);
    Event*operator[](int index);

};


#endif
