/*
 * naloga4_1PRG2.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: ultron
 */

#include "Calendar.h"
#include <iostream>
#include <limits>

using namespace std;

static std::vector<Event*> toVector(Calendar* cal){
    std::vector<Event*> events;
    for(std::pair<std::string, Event*> m : cal->getEvents()){
        events.push_back(m.second);
    }
}

int main(){

	Calendar* cal = new Calendar("Elisey");
	Event* lecEvent = new LectureEvent("Programiranje2", "F-104", DateTime(Date(25, 3, 2019), Time(7,0,0)),
			DateTime(Date(25,3,2019), Time(10,0,0)));
    Event* birEvent = new BirthdayEvent("Rojstni Dan", "Stuk", DateTime(Date(21, 12, 2019), Time(19,30,0)),
                                    DateTime(Date(22,12,2019), Time(0,0,0)));
    Event* metEvent = new MeetingEvent("Sestanek investorjev", "Pisarna", DateTime(Date(1, 3, 2020), Time(13,0,0)),
                                    DateTime(Date(1,3,2020), Time(15,0,0)), "Elisey");
	cal->addEvent(lecEvent);
	cal->addEvent(birEvent);
	cal->addEvent(metEvent);

	cout << cal->toString();
	Event* ev = cal->findEvent("Rojstni Dan");
    if(ev) cout<<ev->toString();
    std::cout << (cal->deleteEvent("Programiranje2") ? "Deleted\n" : "Doesn't exist\n");
    std::cout << cal->numOfEvents() << '\n';

    for(Event* e : cal->toVector(cal)){
        std::cout << e->toString();
    }

    if(!cal->isEmpty()){
        std::cout << cal->count("Sestanek investorjev") << '\n';
    }
    cal->purgeCal();
    std::cout << cal->numOfEvents();
	delete birEvent;
	delete metEvent;
	return 0;
}


