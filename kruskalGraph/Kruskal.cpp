//
// Created by Elisey on 17/05/2019.
//

#include <fstream>
#include <iostream>
#include "Kruskal.h"

void Kruskal::readGraphFromFile(const std::string &pathToFile) {
    int a; //dummy int
    int v1, v2;
    int cena;
    std::ifstream ifs(pathToFile);
    if(ifs){
        ifs >> a >> a;
        while(ifs.peek()!=EOF){
            ifs >> v1 >> v2 >> cena;
            this->voslisca.insert(std::make_pair(v1, 0));
            this->voslisca.insert(std::make_pair(v2, 0));
            this->povezave.push_back(new Povezava(v1, v2, cena));
        }
    } else {
        std::cout << "Ifstream error.\n";
    }
}

Kruskal* Kruskal::generateRandomGraph(const int &numOfNodes) {
    if(numOfNodes > 1500){
        std::cout << "Maksimalno stevilo vozlisc prekoraceno.\n";
        return nullptr;
    }
    Kruskal* k = new Kruskal();
    for(int i = 0; i < numOfNodes; i++){
        k->voslisca.insert(std::make_pair(i, 0));
    }
    for(int i = 0; i < numOfNodes; i++){
        for(int j = 0; j < numOfNodes; j++){
            this->povezave.push_back(new Povezava(i, j, rand() % 100));
        }
    }
    return k;
}

void Kruskal::mostEfficientSubGraph() {

}

void Kruskal::print() {

}

Kruskal::Povezava* Kruskal::divide(Povezava* p1, Povezava* p2){

    int pivot = p1->cena;
    Povezava* dn = p1;
    Povezava* vr = p2;
    bool crossed = false;
    while(!crossed){
        while(dn->cena <= pivot && dn != p2){
            dn = dn->getNext();
            if(vr==dn)crossed=true;
        }
        while(vr->cena >= pivot && vr != p1){
            vr = vr->getPrev();
            if(vr==dn)crossed=true;
        }
        if(!crossed){
            swapValues(vr, dn);
        }
    }
    swapValues(p1, vr);
    return vr;
}

void Kruskal::sortConnections(Povezava* p1, Povezava* p2){
    if(p1 != p2){
        Povezava* j = divide(p1, p2);
        if(j!=p1){
            quickSort(p1, j->getPrev());
        }
        if(j!=p2){
            quickSort(j->getNext(), p2);
        }

    }
}
