/*
 * Calendar.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: ultron
 */
#include "Calendar.h"
#include "Event.h"
#include <string>
#include <vector>

Calendar::Calendar(std::string name):name(name){}

void Calendar::addEvent(Event* event){
	this->events.push_back(event);
}

std::string Calendar::toString() const{
	std::string res = this->name;
	for(Event* i : this->events){
		res+=' ' + i->toString();
	}

	return res;
}