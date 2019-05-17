#include "Huffman.h"

int main(int argc, char* argv[]) {
    if(argc<3) {
        std::cout << "Insufficient arguments.";
        return 0;
    }
    Huffman h;
    std::string pathToFolder = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\huffmanCompression\\";
    std::string filename = argv[2];
    if(argv[1][0] == 'c'){
        h.encode(pathToFolder+filename, pathToFolder+"out.txt");
    } else if(argv[1][0] == 'd'){
        h.decode(pathToFolder+filename, pathToFolder+"out_d.txt");
    } else {
        std::cout << "Wrong first argument.\n";
    }

    return 0;

}