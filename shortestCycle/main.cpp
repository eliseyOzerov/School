#include <iostream>
#include "Cycle.h"

int main() {
    std::string folderPath = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\shortestCycle\\";
    std::string filename = "graf1.txt";
    Cycle c;
    c.readGraphFromFile(folderPath+filename);
    c.shortestCycle();
    return 0;
}