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
#include <iostream>

Calendar::Calendar(){}
Calendar::Calendar(std::string name):name(name){}

void Calendar::addEvent(Event* event){
    //<iterator, bool> pair that's returned by std::map.insert() below
    //the bool is true if new element was inserted and false if it has already existed
    //the iterator points to the newly added or already existing element

	this->events.push_back(event);
}

std::string Calendar::toString() const{
    if(this->events.empty()){
        std::cout << "No events in vector.\n";
        return "";
    }
	std::string res = this->name;
	for(Event* i : this->events){
		res+=' ' + i->toString();
	}

	return res;
}

int Calendar::findEvent(const std::string &name)const{
    for(int i = 0; i<this->events.size(); i++){
        if(this->events[i]->getName() == name){
            return i;
        }
    }
    return -1;
}

bool Calendar::deleteEvent(const std::string &name) {
    int k = this->findEvent(name);
    if(k>-1){
        this->events.erase(this->events.begin()+k);
        return true;
    } else return false;
}

bool Calendar::operator<(const Calendar &cal) {
    return this->numOfEvents() < cal.numOfEvents();
}

bool Calendar::operator>(const Calendar &cal) {
    return this->numOfEvents() > cal.numOfEvents();
}

bool Calendar::operator==(const Calendar &cal) {
    return this->numOfEvents() == cal.numOfEvents();
}

Calendar& Calendar::operator++() {
    for(Event* e : this->events){
        e->startTime.addWeeks(1);
        e->endTime.addWeeks(1);
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Calendar &cal) {
    out << cal.toString();
    return out;
}


Event* Calendar::operator[](int index) {
    return this->events[index];
}

void Calendar::sort(bool (*c)(Event*, Event*)) {
    std::sort(this->events.begin(), this->events.end(), *c);
}

Event* Calendar::find(bool (*c)(Event *)) {
    return *std::find_if(this->events.begin(), this->events.end(), *c);
}

void Calendar::purgeCal() {
    for(Event* e : this->events){
        delete e;
    }
    this->events.clear();
}

void Calendar::printEvents(Calendar::PrintIfMeetingEvent i) {
    std::for_each(this->events.begin(), this->events.end(), i);
}
