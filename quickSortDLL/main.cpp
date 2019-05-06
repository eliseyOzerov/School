#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <time.h>
#include "DLL.h"
#include <chrono>





bool menu(DLL& dll){
    int izbira, velikost;
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff;
    std::cout << "Hitro uredi dvojno-povezan seznam - izbira:\n\n";
    std::cout << "1) Generiraj nakljucno zaporedje\n";
    std::cout << "2) Generiraj narascajoce zaporedje\n";
    std::cout << "3) Izpis zaporedja\n";
    std::cout << "4) Preveri urejenost zaporedja\n";
    std::cout << "5) Izpisi vsoto elementov\n";
    std::cout << "6) Uredi\n";
    std::cout << "7) Konec\n\n";
    std::cout << "Izbira: ";
    while(!(std::cin >> izbira)){
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Input invalid, try again: ";
    }
    switch (izbira){
        case 1:
            std::cout << "Vnesi velikost zaporedja: ";
            while(!(std::cin >> velikost)){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Vnos napacen, poskusi znova: ";
            }
            std::cout << "Generiram zaporedje...\n";
            dll.generateRandomSequence(velikost);
            dll.setFilled(true);
            break;
        case 2:
            std::cout << "Vnesi velikost zaporedja: ";
            while(!(std::cin >> velikost)){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Vnos napacen, poskusi znova: ";
            }
            std::cout << "Generiram zaporedje...\n";
            dll.generateIncreasingSequence(velikost);
            dll.setFilled(true);
            std::cout << "Konec.\n";
            break;
        case 3:
            std::cout << "Zaporedje: ";
            if(!dll.getFilled()) {
                std::cout << "Zaporedje ne obstaja.\n";
                break;
            }
            dll.printList();
            break;
        case 4:
            if(!dll.getFilled()) {
                std::cout << "Zaporedje ne obstaja.\n";
                break;
            }
            std::cout << "Stanje: ";
            if(dll.sorted()){
                std::cout << "Urejeno.\n";
            } else {
                std::cout << "Ni urejeno.\n";
            }
            break;
        case 5:
            if(!dll.getFilled()) {
                std::cout << "Zaporedje ne obstaja.\n";
                break;
            }
            std::cout << "Sestevek vrednosti je: " << std::to_string(dll.sum()) << std::endl;
            break;
        case 6:
            if(!dll.getFilled()) {
                std::cout << "Zaporedje ne obstaja.\n";
                break;
            }
            std::cout << "Sortiram...\n";
            start = std::chrono::system_clock::now();
            dll.quickSort(dll.getHead(), dll.getTail());
            end = std::chrono::system_clock::now();
            diff = end - start;
            std::cout << "Sortirano. Porabljen cas: " << diff.count() << " sekund.\n";
            std::cout << "Zaporedje: ";
            dll.printList();
            break;
        case 7:
            std::cout << "Hvala za uporabo nasega sortirnega programa. Nasvidenje.\n";
            return false;
        default:
            std::cout << "Napacen vnos. Ponovi.";
            break;
    }
    return true;
}

int main() {
    int value;
    DLL dll;
    srand(time(nullptr));
    while(menu(dll)){}
    return 0;

}