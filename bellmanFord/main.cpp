#include <iostream>
#include "BellmanFord.h"

int main() {
    std::string folderPath = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\bellmanFord\\";
    std::string filename = "graf1.txt";
    BellmanFord b;
    b.readGraphFromFile(folderPath+filename);
    return 0;
}