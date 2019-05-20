#include <iostream>
#include "BellmanFord.h"


bool menu(BellmanFord &bF, std::string folderPath) {
    int izbira;
    std::string filepath;
    int N;
    int zacV, koncV;
    std::cout << "Iskanje v globino in sirino - izbira:\n\n";
    std::cout << "1) Preberi graf iz datoteke\n";
    std::cout << "2) Generiraj nakljucen graf\n";
    std::cout << "3) Pozeni algoritem\n";
    std::cout << "4) Izpisi najkrajso pot\n";
    std::cout << "5) Konec\n\n";
    std::cout << "Izbira: ";
    while(!(std::cin>>izbira)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Napacen vnos.\n";
    }
    switch(izbira){
        case 1:
            std::cout << "Vnesi naslov datoteke: ";
            std::cin >> filepath;
            bF.readGraphFromFile(folderPath + filepath);
            std::cout << "Graf ustvarjen.\n";
            break;
        case 2:
            std::cout << "Vnesi stevilo vozlisc: ";
            while(!(std::cin>>N)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Napacen vnos.\n";
            }
            bF.generateRandomGraph(N);
            std::cout << "Graf ustvarjen.\n";
            break;
        case 3:
            std::cout << "Vnesi zacetno vozlisce: ";
            while(!(std::cin>>zacV)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Napacen vnos.\n";
            }
            bF.zacV = zacV;
            bF.done = bF.run(zacV);
            if (bF.done) std::cout << "Najkrajse poti izracunane.\n";
            else std::cout << "Napaka.\n";
            break;
        case 4:
            std::cout << "Vnesi koncno vozlisce: ";
            while(!(std::cin>>koncV)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Napacen vnos.\n";
            }
            if(!(bF.done)){
                std::cout << "Najkrajsa pot se ni izracunana. Glej izbiro 3.\n";
                break;
            }
            bF.printShortestPath(bF.zacV, koncV);
            std::cout << '\n';
            break;
        case 5:
            return false;
        default:
            std::cout << "Napacna izbira.\n";
            break;
    }
    return true;
}
int main() {
    std::string folderPath = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\bellmanFord\\";
    BellmanFord b;
    while(menu(b, folderPath)){}
    return 0;
}