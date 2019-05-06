//
// Created by Elisey on 06/05/2019.
//

#ifndef FUNCTIONTEMPLATES_DATE_H
#define FUNCTIONTEMPLATES_DATE_H
#include <string>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year);
    std::string toString();
    int getDay() const {return this->day;}
    int getMonth() const {return this->month;}
    int getYear() const {return this->year;}
    bool isEqual(const Date& second);
};


#endif //FUNCTIONTEMPLATES_DATE_H
