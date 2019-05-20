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
    return e->getStarttime() < DateTime(Date(lTime->tm_mday, lTime->tm_mon + 1, lTime->tm_year+1900),
            TimeClass(lTime->tm_hour, lTime->tm_min, lTime->tm_sec));
}

int main(){
	Calendar* cal = new Calendar("Elisey");
	Event* lecEvent = new LectureEvent("Programiranje2", "F-104", DateTime(Date(25, 3, 2019), TimeClass(7,0,0)),
			DateTime(Date(25,3,2019), TimeClass(10,0,0)));
    Event* birEvent = new BirthdayEvent("Rojstni Dan", "Stuk", DateTime(Date(21, 12, 2019), TimeClass(19,30,0)),
                                    DateTime(Date(22,12,2019), TimeClass(0,0,0)));
    Event* metEvent = new MeetingEvent("Sestanek investorjev", "Pisarna", DateTime(Date(1, 3, 2020), TimeClass(13,0,0)),
                                    DateTime(Date(1,3,2020), TimeClass(15,0,0)), "Elisey");
	cal->addEvent(lecEvent);
	cal->addEvent(birEvent);
	cal->addEvent(metEvent);
	std::cout << *cal;

    Calendar neu = ++(*cal);
    neu.addEvent(new MeetingEvent("Nek event", "Faks", DateTime(Date(13, 3, 2019), TimeClass(10,0,0)),
            DateTime(Date(13, 3, 2019), TimeClass(11,0,0)), "Leha"));

    std::cout << "Cal is " << (*cal < neu ? "smaller" : "not smaller") << " than neu.\n";
    std::cout << "Cal is " << (*cal > neu ? "bigger" : "not bigger") << " than neu.\n";
    std::cout << "Cal is " << (*cal == neu ? "equal" : "not equal") << " than neu.\n";
    std::cout << "Cal: \n" << *cal << '\n';
    std::cout << "Neu in a vector: \n";

	delete birEvent;
	delete metEvent;
	return 0;
}


