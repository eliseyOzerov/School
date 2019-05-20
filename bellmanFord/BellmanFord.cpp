//
// Created by Elisey on 20/05/2019.
//

#include <iostream>
#include <limits>
#include <random>
#include "BellmanFord.h"

void BellmanFord::readGraphFromFile(const std::string &pathToFile) {
    std::ifstream ifs(pathToFile);
    int c; // cena povezave
    int l; //stevilo vozlisc
    int i = 0; // index notranjih vektorjev
    int j = 0; // index cene povezave
    if(!this->C.empty())this->C.clear();
    if(!this->nodes.empty())this->nodes.clear();
    if(ifs){
        ifs >> l;
        for(int k = 1; k <= l; k++){
            this->nodes.push_back(new Node(k));
        }
        while(ifs.peek() != std::ifstream::traits_type::eof()){
            C.emplace_back(std::vector<int>());
            while(j<l){
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
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,100);
    if(!this->C.empty())this->C.clear();
    if(!this->nodes.empty())this->nodes.clear();

    for(int k = 1; k <= N; k++){
        this->nodes.push_back(new Node(k));
    }

    for(int i = 0; i < N; i++){
        this->C.emplace_back(std::vector<int>());
        for(int j = 0; j<N; j++){
            this->C[i].push_back(dist(rng));
        }
    }
}

bool BellmanFord::run(int index) {
    if(index > this->nodes.size()){
        std::cout << "Vozlisce ne obstaja.\n";
        return false;
    }
    Node* start = this->nodes[index-1];
    for(Node* n : this->nodes){
        n->cena_poti = std::numeric_limits<int>::max();
        n->predhodnik = nullptr;
    }
    start->cena_poti = 0;
    start->predhodnik = nullptr;
    for(int i = 1; i < this->nodes.size()-1; i++){
        for(Node* u : this->nodes){
            for(Node* v : this->nodes){
                if(u == v)continue;
                if(u->cena_poti + C[u->index-1][v->index-1] < v->cena_poti){
                    v->cena_poti = u->cena_poti + C[u->index-1][v->index-1];
                    v->predhodnik = u;
                }
            }
        }
    }
    for(Node* u : this->nodes){
        for(Node* v : this->nodes){
            if(u == v)continue;
            if(u->cena_poti + C[u->index-1][v->index-1] < v->cena_poti){
                return false;
            }
        }
    }
    return true;
}

void BellmanFord::printShortestPath(int from, int to) {
    Node* fromNode = nullptr;
    Node* toNode = nullptr;
    for(Node* n : this->nodes){
        if(n->index == from) fromNode = n;
        if(n->index == to) toNode = n;
    }
    if(fromNode == toNode){
        std::cout << "Pot je " + std::to_string(to);
        return;
    }
    if(toNode->predhodnik == nullptr){
        std::cout << "Med vozlisci " + std::to_string(from) + " in " + std::to_string(to) + " ni poti!\n";
        return;
    } else {
        printShortestPath(from, toNode->predhodnik->index);
        std::cout  << "->" << std::to_string(to);
    }
}

BellmanFord::~BellmanFord() {
    for(Node* n : this->nodes){
        delete n;
    }
}
