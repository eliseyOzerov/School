//
// Created by Elisey on 20/05/2019.
//

#ifndef BELLMANFORD_BELLMANFORD_H
#define BELLMANFORD_BELLMANFORD_H
#include <vector>
#include <string>
#include <fstream>

class BellmanFord {
private:
    struct Node{
        int cena_poti;
        int predhodnik;
    };
    std::vector<std::vector<int>> C;
    std::vector<Node*> nodes;
public:
    void readGraphFromFile(std::string pathToFile, int v);
    void generateRandomGraph(int N);
    bool run(Node* start);
    void printShortestPath();
};


#endif //BELLMANFORD_BELLMANFORD_H
