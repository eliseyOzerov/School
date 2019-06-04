//
// Created by Elisey on 03/06/2019.
//

#ifndef WEIGHTGENERATOR_DATE_H
#define WEIGHTGENERATOR_DATE_H


#include <string>

class Date {
private:
    int day;
    int month;
    int year;
    static constexpr int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Date(int d, int m, int y):year(y), month(m), day(d){}
    bool isEqual(const Date& second) const;
    std::string toString() const;
    Date operator+(int num);
    static const int* getMonths(){return &Date::months[0];}
};


#endif //WEIGHTGENERATOR_DATE_H
