/*
 * MeetingEvent.h
 *
 *  Created on: Mar 25, 2019
 *      Author: ultron
 */
#ifndef MEETING_EVENT_H_
#define MEETING_EVENT_H_
#include "Event.h"
#include <string>


class MeetingEvent: public Event{
private:
	std::string person;
public:
	MeetingEvent(std::string name, std::string location, DateTime startDate, DateTime endDate, std::string person);
	std::string toString();
	Repetition getRepetition() const override {return Repetition::none;}
};


#endif
