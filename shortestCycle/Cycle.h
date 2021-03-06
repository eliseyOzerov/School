//
// Created by Elisey on 21/05/2019.
//

#ifndef SHORTESTCYCLE_CYCLE_H
#define SHORTESTCYCLE_CYCLE_H
#include <vector>
#include <string>
#include <array>
#include <bitset>

class Cycle {
private:
    struct Pot{
        int izV;
        int vV;
        int cena;
        std::bitset<12> vozlNP; //vozlisca na poti
        Pot(int izV, int vV, int cena) : izV(izV), vV(vV), cena(cena) {}
    };
    std::vector<Pot*> potiNaNivoju;
    std::vector<std::vector<int>> matrikaSosednosti;
public:
    void readGraphFromFile(std::string filePath);
    int shortestCycle();
};


#endif //SHORTESTCYCLE_CYCLE_H
