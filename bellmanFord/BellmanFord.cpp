//
// Created by Elisey on 20/05/2019.
//

#include <iostream>
#include <limits>
#include "BellmanFord.h"

void BellmanFord::readGraphFromFile(std::string pathToFile, int v) {
    std::ifstream ifs(pathToFile);
    int c; // cena povezave
    int i = 0; // index notranjih vektorjev
    int j = 0; // index cene povezave
    if(ifs){
        ifs >> c;
        while(ifs.peek() != std::ifstream::traits_type::eof()){
            C.push_back(std::vector<int>());
            while(j<v){
                ifs >> c;
                C[i].push_back(c);
                j++;
            }
            i++;
            j = 0;
        }
    } else {
        std::cout << "Ifstream error.\n";
        return;
    }
}

void BellmanFord::generateRandomGraph(int N) {

}

bool BellmanFord::run(Node* start) {
    for(Node* n : this->nodes){
        n->cena_poti = std::numeric_limits<int>::max();
        n->predhodnik = -1;
    }
    start->cena_poti = 0;
    start->predhodnik = -1;
    for(int i = 0)
}

void BellmanFord::printShortestPath() {

}
