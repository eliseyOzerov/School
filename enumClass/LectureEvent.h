//
// Created by Elisey on 15/04/2019.
//

#ifndef LECTUREEVENT_H
#define LECTUREEVENT_H
#include "Event.h"

class LectureEvent: public Event {
public:
    LectureEvent(std::string name, std::string location, DateTime start, DateTime end): Event(name, location, start, end){}
    Repetition getRepetition() const override {return Repetition::weekly;}
};


#endif //LECTUREEVENT_H
