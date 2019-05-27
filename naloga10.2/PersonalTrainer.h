//
// Created by Elisey on 26/05/2019.
//

#ifndef NALOGA10_2_PERSONALTRAINER_H
#define NALOGA10_2_PERSONALTRAINER_H
#include "Teacher.h"

class PersonalTrainer: virtual public Teacher{
public:
    PersonalTrainer(int exp) : Teacher(exp){
        std::cout << "PersonalTrainer called.\n";
    }
};


#endif //NALOGA10_2_PERSONALTRAINER_H
