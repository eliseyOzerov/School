#include <iostream>
#include "Kruskal.h"

int main() {
    std::string folderPath = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\kruskalGraph\\";
    std::string filename = "graf.txt";
    Kruskal k;
    k.readGraphFromFile(folderPath+filename);
    return 0;
}