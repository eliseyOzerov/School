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
#include <typeinfo>
#include <iostream>

class Calendar{
private:
	std::string name;
	std::vector<Event*> events;
public:
    class PrintIfMeetingEvent{
    public:
        void operator()(Event* e){
            if(dynamic_cast<MeetingEvent*>(e)){
                std::cout << e->toString();
            }
        }
    };
    std::vector<Event*> getEvents() const {return this->events;}
    Calendar();
	Calendar(std::string name);
	std::string toString() const;
	void addEvent(Event* event);
    int numOfEvents() const {return this->events.size();}

	int findEvent(const std::string &name) const;
	bool deleteEvent(const std::string &name);
	bool isEmpty(){return events.empty();}
	void purgeCal();

	//naloga 10.1
    void sort(bool (*c)(Event*, Event*));
    Event* find(bool (*c)(Event*));
    void printEvents(PrintIfMeetingEvent i);
    //std::cout<<calendar->find(isAfterCurrentTime)->toString();

    //naloga 9.1
    bool operator<(const Calendar& cal);
	bool operator>(const Calendar& cal);
	bool operator==(const Calendar& cal);
    Calendar& operator++();
    friend std::ostream& operator << (std::ostream &out, const Calendar &cal);
    Event* operator[](int index);

};


#endif
