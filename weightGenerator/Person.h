//
// Created by Elisey on 03/06/2019.
//

#ifndef WEIGHTGENERATOR_PERSON_H
#define WEIGHTGENERATOR_PERSON_H
#include <string>
#include "Date.h"

class Person {
private:
    std::string name;
    const Date* birthDate;
    int height;
public:
    Person(std::string n, const Date &d, int h);
    std::string toString() const;
};


#endif //WEIGHTGENERATOR_PERSON_H
