//
// Created by Elisey on 06/05/2019.
//

#ifndef MYSTACK_DATE_H
#define MYSTACK_DATE_H
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


#endif //MYSTACK_DATE_H
