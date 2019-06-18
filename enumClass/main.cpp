/*
 * naloga4_1PRG2.cpp
 *
 *  Created on: Mar 25, 2019
 *      Author: ultron
 */

#include "Calendar.h"
#include <iostream>
#include <limits>


bool isAfterCurrentTime(Event* e) {
    auto ct = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(ct);
    tm * lTime = localtime(&time);
    return e->startTime > DateTime(Date(lTime->tm_mday, lTime->tm_mon + 1, lTime->tm_year+1900),
            TimeClass(lTime->tm_hour, lTime->tm_min, lTime->tm_sec));
}

bool ascendingDates(Event* i, Event* j) {
    return j->startTime > i->startTime;
}

bool descendingDates(Event* i, Event* j) {
    return j->startTime < i->startTime;
}

bool ascendingNames(Event* i, Event* j) {
    return j->getName() > i->getName();
}

int main(){
	Calendar cal;
	cal.addEvent(new LectureEvent("C", "F-104", DateTime(Date(18, 1, 2009), TimeClass(7,0,0)),
			DateTime(Date(25,3,2019), TimeClass(10,0,0))));
    cal.addEvent(new BirthdayEvent("A", "Stuk", DateTime(Date(21, 6, 2013), TimeClass(19,30,0)),
                                    DateTime(Date(22,12,2019), TimeClass(0,0,0))));
    cal.addEvent(new MeetingEvent("D", "Pisarna", DateTime(Date(1, 11, 2005), TimeClass(13,0,0)),
                                    DateTime(Date(1,3,2020), TimeClass(15,0,0)), "Elisey"));
    cal.addEvent(new MeetingEvent("B", "Faks", DateTime(Date(13, 9, 2019), TimeClass(10,0,0)),
            DateTime(Date(13, 3, 2019), TimeClass(11,0,0)), "Leha"));

    ++cal;


    std::cout << "Ascending dates:\n";
    cal.sort(ascendingDates);
    for(Event* e : cal.getEvents()){
        std::cout << e->startTime.getDate().toString() << '\n';
    }

    std::cout << cal;

    std::cout<<cal.find(isAfterCurrentTime)->toString();

    std::cout << "Descending dates:\n";
    cal.sort(descendingDates);
    for(Event* e : cal.getEvents()){
        std::cout << e->startTime.getDate().toString() << '\n';
    }

    std::cout << "Ascending names:\n";
    cal.sort(ascendingNames);
    for(Event* e : cal.getEvents()){
        std::cout << e->getName() << '\n';
    }

    Calendar::PrintIfMeetingEvent meet;
    cal.printEvents(meet);

    cal.purgeCal();
	return 0;
}


