/*
 * MeetingEvent.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: ultron
 */

#include "MeetingEvent.h"

#include <string>
#include <iostream>

MeetingEvent::MeetingEvent(std::string name, std::string location, DateTime startDate, DateTime endDate, std::string person) : Event(name, location,
		startDate, endDate), person(person){}

std::string MeetingEvent::toString(){
	std::string res;

	res = Event::toString() + "\nPerson: " + this->person;

	return res;
}
