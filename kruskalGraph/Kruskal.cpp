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
            this->vozlisca.insert(std::make_pair(v1, 0));
            this->vozlisca.insert(std::make_pair(v2, 0));
            this->povezave.push_back(new Povezava(v1, v2, cena));
        }
    } else {
        std::cout << "Ifstream error.\n";
    }
    this->sortConnections(this->povezave, 0, this->povezave.size()-1);
    for(auto c : this->povezave){
        std::cout << c->v1 << " -> " << c->v2 << " : " << c->cena <<'\n';
    }
}

void Kruskal::generateRandomGraph(const int &numOfNodes) {
    if(numOfNodes > 1500){
        std::cout << "Maksimalno stevilo vozlisc prekoraceno.\n";
        return;
    }
    this->povezave.clear();
    this->vozlisca.clear();
    for(int i = 0; i < numOfNodes; i++){
        this->vozlisca.insert(std::make_pair(i, 0));
    }
    for(int i = 0; i < numOfNodes; i++){
        for(int j = 0; j < numOfNodes; j++){
            if(i!=j) this->povezave.push_back(new Povezava(i, j, rand() % 100 + 1));
        }
    }
    this->sortConnections(this->povezave, 0, this->povezave.size()-1);
    for(auto c : this->povezave){
        std::cout << c->v1 << " -> " << c->v2 << " : " << c->cena <<'\n';
    }
}

void Kruskal::mostEfficientSubGraph() {
    std::vector<Povezava*> res;
    for(Povezava* p : this->povezave){
        auto v1it = this->vozlisca.find(p->v1);
        auto v2it = this->vozlisca.find(p->v2);
        //ce nobeno vozlisce ni v podgrafu
        if(v1it->second == 0 && v2it->second == 0){
            res.push_back(p);
            v1it->second = ++this->steviloMnozic;
            v2it->second = this->steviloMnozic;
        } else if (v1it->second != v2it->second){
            res.push_back(p);
            if(!(v1it->second)){//ce prvo vozlisce ni v podgrafu
                v1it->second = v2it->second;
            } else if(!(v2it->second)){//ce drugo vozlisce ni v podgrafu
                v2it->second = v1it->second;
            } else {//ce sta v razlicnih podgrafih
                int k = v2it->second;
                for(auto &v : this->vozlisca){
                    if(v.second == k){
                        v.second = v1it->second;
                    }
                }
            }
        }
    }
    this->optPodgraf = res;
}

void Kruskal::print(const std::vector<Povezava*> &res) {
    if(res.size() == this->vozlisca.size() - 1){
        std::cout << "Najbolj optimalen vpet podgraf: \n";
        for(Povezava* p : res){
            std::cout << p->v1 << " -> " << p->v2 << " : " << p->cena << '\n';
        }
    } else {
        std::cout << "Ni resitve.\n";
    }
}

int Kruskal::divide(std::vector<Povezava*> &v, int dno, int vrh){
    int pivot = v[dno]->cena;
    int dn = dno;
    int vr = vrh;
    while(vr>dn){
        while(v[dn]->cena <= pivot && dn < vrh){
            dn++;
        }
        while(v[vr]->cena >= pivot && vr > dno){
            vr--;
        }
        if(vr > dn){
            std::swap(v[dn], v[vr]);
        }
    }
    std::swap(v[dno], v[vr]);
    return vr;
}

void Kruskal::sortConnections(std::vector<Povezava*> &v, int dno, int vrh){
    if(dno < vrh){
        int j = divide(v, dno, vrh);
        sortConnections(v, dno, j-1);
        sortConnections(v, j+1, vrh);
    }
}
