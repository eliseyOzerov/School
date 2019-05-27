//
// Created by Elisey on 26/05/2019.
//

#ifndef NALOGA10_2_TEACHER_H
#define NALOGA10_2_TEACHER_H
#include <iostream>
#include <string>

class Teacher {
public:
    std::string name;
    int experience;
    Teacher(int exp) : experience(exp){
        std::cout << "Teacher called.\n";
    }
};


#endif //NALOGA10_2_TEACHER_H
