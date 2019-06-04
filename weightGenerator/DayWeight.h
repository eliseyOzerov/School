//
// Created by Elisey on 03/06/2019.
//

#ifndef WEIGHTGENERATOR_DAYWEIGHT_H
#define WEIGHTGENERATOR_DAYWEIGHT_H

#include "Date.h"

class DayWeight {
private:
    double weight;
    Date date;
public:
    DayWeight(double weight, Date &d) : weight(weight), date(d){}
    std::string toString() const;
    bool isDateEqual(const DayWeight& other) const; // primerjamo dva objekta date
    bool operator <(const DayWeight& other); // primerjamo weight
    bool operator >(const DayWeight& other); // primerjamo weight
    bool operator >(double other); // primerjamo weight z other
    void setWeight(const double w){this->weight = w;}
    double getWeight()const{return this->weight;}
    void setDate(const Date &d){this->date = d;}
    Date getDate()const{return this->date;}
};


#endif //WEIGHTGENERATOR_DAYWEIGHT_H
