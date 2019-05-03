//
// Created by Elisey on 15/04/2019.
//

#ifndef BIRTHDAYEVENT_H
#define BIRTHDAYEVENT_H

#include "Event.h"

class BirthdayEvent: public Event {
public:
    BirthdayEvent(std::string name, std::string location, DateTime start, DateTime end) : Event(name, location, start, end){}
    Repetition getRepetition(){return Repetition ::yearly;}
};


#endif //BIRTHDAYEVENT_H
