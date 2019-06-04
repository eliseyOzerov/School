//
// Created by Elisey on 03/06/2019.
//

#ifndef WEIGHTGENERATOR_WEIGHTTRACKER_H
#define WEIGHTGENERATOR_WEIGHTTRACKER_H
#include <vector>

#include "Person.h"
#include "DayWeight.h"

class WeightTracker {
private:
    Person person;
    std::vector<DayWeight> dW;
    bool contains(const DayWeight& event) const;// privatna metoda, preveri ali imamo v vektorju weights že zapis za date (kličemo metodo isDateEqual iz razreda DayWeight
public:
    WeightTracker(const Person &p) : person(p){}
    void readFromFile(std::string fileName); // preberemo vse meriteve tež iz priložene datoteke
    void addWeight(const DayWeight& event); // dodamo težo za posamezen dan
    const DayWeight& find(const Date& date) ; // najdemo težo za posamezen dan
    double averageWeight() const; // izračunamo povprečno težo
    int aboveAverage() const; // število dni ko je bila teža nad povprečjem
    const DayWeight& minDayWeight() const; // najdemo dan z minimalno težo
    const DayWeight& maxDayWeight() const; //najdemo težo z maximalno težo
    std::string toString() const;
};


#endif //WEIGHTGENERATOR_WEIGHTTRACKER_H
