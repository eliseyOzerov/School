/*
 * Event.cpp
 *
 *  Created on: Mar 24, 2019
 *      Author: ultron
 */


#include "Event.h"
#include "DateTime.h"
#include <iostream>
#include <string>

Event::Event(std::string name, std::string location,
		DateTime startTime, DateTime endTime):
		name(name), location(location),
		startTime(startTime), endTime(endTime){}

Event::Repetition Event::getRepetition() const{}

std::string Event::getRepetitionString(const Event::Repetition &r) {
    std::string res;
    switch (r){
        case Repetition::none:
            res = "None";
            break;
        case Repetition::daily:
            res = "Daily";
            break;
        case Repetition::weekly:
            res = "Weekly";
            break;
        case Repetition::monthly:
            res = "Monthly";
            break;
        case Repetition::yearly:
            res = "Yearly";
            break;
        default:
            res = "Error";
            break;
    }
    res+="\n\n";
    return res;
}

std::string Event::toString() const{
	std::string res;

	res="Event:\nName: " + this->name + " Location: " + this->location +
			" \nStart: " + this->startTime.toString() + " End: " + this->endTime.toString() + " Repeat: " + Event::getRepetitionString(getRepetition());

	return res;
}
