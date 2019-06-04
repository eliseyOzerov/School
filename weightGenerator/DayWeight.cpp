//
// Created by Elisey on 03/06/2019.
//

#include <sstream>
#include "DayWeight.h"

std::string DayWeight::toString() const {
    std::stringstream ss;
    ss << "Date: " << this->date.toString() << " Weight: " << this->weight << '\n';
    return ss.str();
}

bool DayWeight::isDateEqual(const DayWeight &other) const {
    return this->date.isEqual(other.date);
}

bool DayWeight::operator<(const DayWeight &other) {
    return this->weight < other.weight;
}

bool DayWeight::operator>(const DayWeight &other) {
    return this->weight > other.weight;
}

bool DayWeight::operator>(double other) {
    return this->weight > other;
}
