#include <iostream>
#include <cmath>
#include <fstream>
#include <limits>
#include <time.h>
#include <random>
#include <map>
#include "kMeans.h"


int main(int argc, char* argv[]) {
    if(argc < 4){
        std::cout << "Premalo argumentov.\n";
        return 0;
    }
    int stIter = atoi(argv[1]);

    if(stIter < 0){
        std::cout << "Neveljavno stevilo iteracij.\n";
        return 0;
    }
    int stGruc = atoi(argv[2]);
    if(stGruc < 0){
        std::cout << "Neveljavno stevilo gruc.\n";
        return 0;
    }

    std::string filepath = "./" + std::string(argv[3]);
    std::ofstream ofs("./out.txt", std::ios::trunc);

    kMeans km(stGruc, stIter);

    km.readData(filepath);

    for(int i = 0; i<km.stIter; i++){
        km.newClusterCenters();
        km.assignPointsToClusters();
    }
    if(stGruc <= 10){
        km.printGraph();
    }
    km.printPoints(ofs);
    return 0;
}