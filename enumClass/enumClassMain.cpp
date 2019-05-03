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
	delete lecEvent;
	delete birEvent;
	delete metEvent;
	return 0;
}


