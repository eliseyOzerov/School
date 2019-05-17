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
    this->sortConnections(0, this->povezave.size()-1);
    for(auto c : this->povezave){
        std::cout << c->v1 << " -> " << c->v2 << " : " << c->cena <<'\n';
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

int Kruskal::divide(int dno, int vrh){
    int pivot = this->povezave.front()->cena;
    int dn = dno;
    int vr = vrh;
    while(vr>dn){
        while(this->povezave[dn]->cena <= pivot && dn < vrh){
            dn++;
        }
        while(this->povezave[vr]->cena >= pivot && vr > dno){
            vr--;
        }
        if(vr > dn){
            std::swap(this->povezave[dn], this->povezave[vr]);
        }
    }
    std::swap(this->povezave[dno], this->povezave[vr]);
    return vr;
}

void Kruskal::sortConnections(int dno, int vrh){
    if(dno < vrh){
        int j = divide(dno, vrh);
        sortConnections(dno, j-1);
        sortConnections(j+1, vrh);
    }
}
