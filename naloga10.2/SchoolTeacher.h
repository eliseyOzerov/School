//
// Created by Elisey on 26/05/2019.
//

#ifndef NALOGA10_2_SCHOOLTEACHER_H
#define NALOGA10_2_SCHOOLTEACHER_H
#include "Teacher.h"

class SchoolTeacher: virtual public Teacher {
public:
    SchoolTeacher(int exp) : Teacher(exp){
        std::cout << "SchoolTeacher called.\n";
    }
};


#endif //NALOGA10_2_SCHOOLTEACHER_H
