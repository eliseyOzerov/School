//
// Created by Elisey on 06/05/2019.
//

#ifndef FUNCTIONTEMPLATES_TEMPLATES_H
#define FUNCTIONTEMPLATES_TEMPLATES_H
#include <vector>
#include <string>
#include "Date.h"

template<typename T> void printVector(const std::vector<T> &vec){
    for(T t: vec){
        std::cout << t << ' ';
    }
    std::cout << '\n';
}

template<> void printVector(const std::vector<Date> &vec){
    for(Date i : vec){
        std::cout << i.toString() << ' ';
    }
    std::cout << '\n';
}
template<typename T> void reorder(T &x, T&y){
    T t = y;
    y = x;
    x = t;
}

template<typename T> bool isAfter(const T &x, const T&y){
    return x>y;
}

template<> bool isAfter<std::string>(const std::string &x, const std::string &y){
    return !(x.size() <= y.size());
}

template<> bool isAfter<Date>(const Date &x, const Date &y){
    if(y.getYear() > x.getYear()) {
        return false;
    }
    if(y.getMonth() > x.getMonth()){
        return false;
    }

    if(y.getDay() >= x.getDay()){
        return false;
    }

    return true;
}

template<typename T> void bubbleSort(std::vector<T>& vec, bool order){
    if(order){
        for (int i = 0; i < vec.size()-1; i++)

            // Last i elements are already in place
            for (int j = 0; j < vec.size()-i-1; j++)
                if (vec[j] > vec[j+1])
                    reorder(vec[j], vec[j+1]);
    } else {
        for (int i = 0; i < vec.size()-1; i++)

            // Last i elements are already in place
            for (int j = 0; j < vec.size()-i-1; j++)
                if (vec[j] < vec[j+1])
                    reorder(vec[j], vec[j+1]);
    }

}

#endif //FUNCTIONTEMPLATES_TEMPLATES_H
