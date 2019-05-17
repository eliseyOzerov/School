#include <iostream>
#include "Graph.h"
#include <map>
#include <unordered_map>
#include <math.h>
#include <string>
#include <chrono>

int main() {
    Graph<int> g;
    Graph<int> gB;
    Graph<std::string> gI;
    std::string folderPath = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\graphTraversal\\";
    std::string grafPath = "graf.txt";
    std::string grafBigPath = "grafBig.txt";
    std::string grafImena = "grafImena.txt";
    while(g.menu(folderPath)){}
    while(gB.menu(folderPath)){}
    while(gI.menu(folderPath)){}
    return 0;
}