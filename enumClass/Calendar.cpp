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

Calendar::Calendar(std::string name):name(name){}

bool Calendar::addEvent(Event* event){
    //<iterator, bool> pair that's returned by std::map.insert() below
    //the bool is true if new element was inserted and false if it has already existed
    //the iterator points to the newly added or already existing element

	auto ret = this->events.insert( std::pair<std::string, Event*>(event->getName(), event) );
	return ret.second;
}

std::string Calendar::toString() const{
	std::string res = this->name;
	for(std::pair<std::string, Event*> i : this->events){
		res+=' ' + i.second->toString();
	}

	return res;
}

Event* Calendar::findEvent(const std::string &name)const{
    auto it = this->events.find(name);
    if(it != this->events.end()){
        return this->events.find(name)->second;
    } else {
        return nullptr;
    }
}

bool Calendar::deleteEvent(const std::string &name) {
    auto it = this->events.find(name);
    if(it != this->events.end()){
        delete it->second;
        this->events.erase(it);
        return true;
    } else {
        return false;
    }
}

std::vector<Event*> Calendar::toVector() {
    for(std::pair<std::string, Event*> p : this->getEvents()){
        this->eventsVec.push_back(p.second);
    }
    return this->eventsVec;
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
    for(const auto &e : this->events){
        e.second->getStarttime().addWeeks(1);
        e.second->getEndtime().addWeeks(1);
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Calendar &cal) {
    out << cal.toString();
    return out;
}


Event *Calendar::operator[](int index) {
    return this->toVector()[index];
}

void Calendar::sort(bool (*c)(Event*, Event*)) {
    std::sort(eventsVec.begin(), eventsVec.end(), *c);
}

bool ascendingDates(Event* i, Event* j) {
    return j->getStarttime().getDate() > i->getStarttime().getDate();
}

bool descendingDates(Event* i, Event* j) {
    return i->getStarttime().getDate() < j->getStarttime().getDate();
}

bool ascendingNames(Event* i, Event* j) {
    return j->getName() > i->getName();
}

Event* Calendar::find(bool (*c)(Event *)) {
    if(this->eventsVec.empty()){
        this->toVector();
    }
    return *std::find_if(this->eventsVec.begin(), this->eventsVec.end(), *c);
}
