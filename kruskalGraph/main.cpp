#include <iostream>
#include <limits>
#include <time.h>
#include "Kruskal.h"
bool menu(Kruskal &k, std::string folderPath){
    int izbira;
    int n;//stevilo vozlisc
    std::string pot;
    std::cout << "Kruskalov algoritem - izbira: \n\n";
    std::cout << "1) Preberi graf iz datoteke\n";
    std::cout << "2) Generiraj nakljucni graf\n";
    std::cout << "3) Pozeni\n";
    std::cout << "4) Izpis sprejetih povezav\n";
    std::cout << "5) Konec\n\n";
    std::cout << "Izbira: ";
    while(!(std::cin >> izbira)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Napacen vnos.\n";
    }
    switch(izbira){
        case 1:
            std::cout << "Vnesi naslov datoteke: ";
            std::cin >> pot;
            std::cout << "Graf iz datoteke: \n";
            k.readGraphFromFile(folderPath + pot);
            break;
        case 2:
            std::cout << "Vnesi stevilo vozlisc [max 1500]: ";
            while(!(std::cin >> n)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Napacen vnos.\n";
            }
            std::cout << "Nakljucen graf: \n";
            k.generateRandomGraph(n);
            break;
        case 3:
            std::cout << "Racunam...\n";
            k.mostEfficientSubGraph();
            std::cout << "Konec.\n";
            break;
        case 4:
            k.print(k.getSubgraph());
            break;
        case 5:
            std::cout << "Konec\n";
            return false;
        default:
            std::cout << "Napacen vnos.\n";
            break;
    }
    return true;
}
int main() {
    srand(time(nullptr));
    std::string folderPath = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\kruskalGraph\\";
    std::string filename = "graf.txt";
    Kruskal k;
    while(menu(k, folderPath)){}
    return 0;
}