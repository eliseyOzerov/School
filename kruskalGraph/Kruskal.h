//
// Created by Elisey on 17/05/2019.
//

#ifndef KRUSKALGRAPH_KRUSKAL_H
#define KRUSKALGRAPH_KRUSKAL_H
#include <vector>
#include <unordered_map>

class Kruskal {
private:
    struct Povezava{
        int* v1;
        int* v2;
        int cena;
        Povezava(int v1, int v2, int cena):v1(&v1), v2(&v2), cena(cena){}
    };
    std::vector<Povezava*> povezave; //idV1, idV2, cena //vse povezave s cenami, dolocene neusmerjeno
    std::unordered_map<int, int> voslisca; //vozlisce, podgraf : evidenca podgrafov in njihovih vozlisc
    void sortConnections(Povezava* p1, Povezava* p2); //quickSort
    Povezava* divide(Povezava* p1, Povezava* p2); //quickSort division
public:
    void readGraphFromFile(const std::string &pathToFile);
    Kruskal* generateRandomGraph(const int &numOfNodes);
    void mostEfficientSubGraph();
    void print();
};


#endif //KRUSKALGRAPH_KRUSKAL_H
