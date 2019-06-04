//
// Created by Elisey on 30/05/2019.
//

#ifndef KMEANS_KMEANS_H
#define KMEANS_KMEANS_H
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <fstream>
#include <iostream>

struct Gruca;

struct Tocka{
    double x;
    double y;
    int index;
    Gruca* gruca;
    Tocka(int index, double x, double y, Gruca* gruca) : index(index), x(x), y(y), gruca(gruca){}
};

struct Gruca{
    std::set<Tocka*> tocke; //to rabimo za lazji izracun novega sredisca gruce
    int index;
    Tocka* center;
    Gruca(int index, Tocka* center) : index(index), center(center){}
};

class kMeans {
public:
    kMeans(int stGruc, int stIter) : stGruc(stGruc), stIter(stIter){}
    int stGruc; //stevilo gruc
    int stIter; //stevilo iteracij
    double xMin, xMax;
    double yMin, yMax;
    std::vector<Tocka*> rawData;
    std::vector<Gruca*> gruce;
    std::vector<std::vector<std::string>> graph;
    void createRandomData(int stTock);
    double getDistance(Tocka* a, Tocka* b);
    void setRanges();
    void readData(const std::string &path);
    void assignPointsToClusters();
    void newClusterCenters();
    void printPoints(std::ofstream &ofs);
    void fillGraph();
    void printGraph();
};


#endif //KMEANS_KMEANS_H
