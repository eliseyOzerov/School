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

std::vector<Event*> Calendar::toVector(Calendar *cal) {
    std::vector<Event*> pE;
    for(std::pair<std::string, Event*> p : cal->getEvents()){
        pE.push_back(p.second);
    }
    return pE;
}
