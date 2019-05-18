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
        int v1;
        int v2;
        int cena;
        Povezava(int &v1, int &v2, int cena):v1(v1), v2(v2), cena(cena){}
    };
    int steviloMnozic = 0;
    std::vector<Povezava*> povezave; //idV1, idV2, cena : vse povezave s cenami, dolocene neusmerjeno
    std::vector<Povezava*> optPodgraf;
    std::unordered_map<int, int> vozlisca; //vozlisce, podgraf : evidenca podgrafov in njihovih vozlisc
    void sortConnections(std::vector<Povezava*> &v, int dno, int vrh); //quickSort
    int divide(std::vector<Povezava*> &v, int dno, int vrh); //quickSort division
public:
    ~Kruskal(){
        for(Povezava* p : this->povezave){
            delete p;
        }
    }
    std::vector<Povezava*> getSubgraph(){return this->optPodgraf;}
    void readGraphFromFile(const std::string &pathToFile);
    void generateRandomGraph(const int &numOfNodes);
    void mostEfficientSubGraph();
    void print(const std::vector<Povezava*> &res);
};


#endif //KRUSKALGRAPH_KRUSKAL_H
