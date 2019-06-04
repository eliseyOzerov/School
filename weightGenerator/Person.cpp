//
// Created by Elisey on 03/06/2019.
//

#include <sstream>
#include "Person.h"

std::string Person::toString() const {
    std::stringstream ss;
    ss << "Name: " << this->name << " Birth date: " << this->birthDate << " Height: " << this->height << '\n';
    return ss.str();
}

Person::Person(std::string n, const Date &d, int h) : name(n), birthDate(&d), height(h){}