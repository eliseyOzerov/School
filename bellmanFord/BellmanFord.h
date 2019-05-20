//
// Created by Elisey on 20/05/2019.
//

#ifndef BELLMANFORD_BELLMANFORD_H
#define BELLMANFORD_BELLMANFORD_H
#include <vector>
#include <string>
#include <fstream>
#include <limits>

class BellmanFord {
private:
    struct Node{
        unsigned int index;
        unsigned int cena_poti;
        Node* predhodnik;
        Node(int index) : index(index){}
    };
    std::vector<std::vector<int>> C; //matrika sosednosti
    std::vector<Node*> nodes;
public:
    bool done = false;
    int zacV;
    ~BellmanFord();
    void readGraphFromFile(const std::string &pathToFile);
    void generateRandomGraph(int N);
    bool run(int index);
    void printShortestPath(int fromNode, int toNode);
};


#endif //BELLMANFORD_BELLMANFORD_H
