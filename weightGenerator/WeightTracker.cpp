//
// Created by Elisey on 03/06/2019.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "WeightTracker.h"

bool WeightTracker::contains(const DayWeight &event) const {
    for(const DayWeight &d : this->dW){
        if(d.isDateEqual(event)) return true;
    }
    return false;
}

void WeightTracker::readFromFile(std::string fileName) {
    std::ifstream ifs("./"+fileName);
    if(!ifs) std::cerr << strerror(errno);
    std::string s;
    std::vector<std::string> sV;
    while(ifs.peek() != EOF){
        std::getline(ifs, s);
        if(!s.empty()){
            sV.emplace_back("");
            for(const char &c : s){
                if(c!=' '){
                    sV.back()+=c;
                } else {
                    sV.emplace_back("");
                }
            }
            if(sV.size()>4)throw std::invalid_argument(s);
            if(sV[1].size() > 10 || sV[1].size() < 8) throw std::invalid_argument(sV[1]);
            std::string intS = "";
            int date[3];
            int i = 0;
            for(const char &c : sV[1]){
                if(c=='.' || c == '\0'){
                    try{
                        date[i] = std::stoi(intS);
                        if(date[i] < 1) throw std::invalid_argument(std::to_string(date[i]));
                        i++;
                        intS = "";
                    } catch (const std::invalid_argument &a){
                        std::cerr << a.what() << '\n';
                    }
                } else {
                    intS += c;
                }
            }
            if(date[1]>12) throw std::invalid_argument(intS);
            if(date[0] > Date::getMonths()[date[0]]) throw std::invalid_argument(intS);
            try{
                double weight = std::stod(sV[3]);
                Date d = Date(date[0], date[1], date[2]);
                this->dW.emplace_back(DayWeight(weight, d));
            } catch (const std::invalid_argument &a){
                std::cerr << a.what() << '\n';
            }

            sV.clear();
        }
    }
}


