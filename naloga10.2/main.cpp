#include <iostream>
#include "Teacher.h"
#include "PersonalTrainer.h"
#include "SchoolTeacher.h"

class Account: public PersonalTrainer, public SchoolTeacher{
public:
    Account(int exp) : Teacher(exp), PersonalTrainer(exp), SchoolTeacher(exp) {
        std::cout << "Account called.\n";
    }
};

int main() {
    Account acc(10);
    std::cout << acc.experience;
    return 0;
}