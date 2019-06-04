#include <iostream>
#include <limits>
#include <chrono>
#include "Cycle.h"

bool menu(Cycle &c, std::string folderpath){
    int izbira;
    std::string filename;
    std::cout << "Trgovski potnik - izbira: \n\n";
    std::cout << "1) Preberi graf iz matrike\n";
    std::cout << "2) Resi problem\n";
    std::cout << "3) Konec\n\n";
    std::cout << "Izbira: ";
    while(!(std::cin >> izbira)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input. Try again.\n";
    }
    switch (izbira){
        case 1:
            std::cout << "Vnesi naslov datoteke: ";
            std::cin >> filename;
            c.readGraphFromFile(folderpath+filename);
            std::cout << "Prebrano.\n";
            break;
        case 2:{
            std::cout << "Racunam...\n";
            auto start = std::chrono::system_clock::now();
            int cena = c.shortestCycle();
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double, std::milli> dur = end - start;
            std::cout << "Pot izracunana. Cas trajanja: " << dur.count() << " milisekund.\n";
            std::cout << "Cena: " << cena << '\n';
            break;
        }
        case 3:
            std::cout << "Konec. Zapiram...\n";
            return false;
        default:
            std::cout << "Napacen vnos. Ponovi.\n";
            break;
    }
    return true;
}

int main() {
    std::string folderPath = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\shortestCycle\\";
    std::string filename = "graf2.txt";
    Cycle c;
    c.readGraphFromFile(folderPath+filename);
    auto start = std::chrono::system_clock::now();
    int cena = c.shortestCycle();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> dur = end - start;
    std::cout << "Cas trajanja: " << dur.count() << " milisekund.\n";
    std::cout << "Cena je: " << cena << '\n';
    return 0;
}