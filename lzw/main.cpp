#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <fstream>
#include <string>
#include <queue>
#include <cstring>
#include "bitstream.h"

namespace global {
    const int dictSize = 256;
    int maxDictSize;
    int maxBitLen;
}

void compress(std::string inFile, std::string outFile){
    std::ifstream ifs(inFile, std::ios::binary);
    std::string T = "";
    std::unordered_map<std::string, int> dictionary;
    bitstream bs;
    char currChar;

    const auto resetDictionary = [&dictionary]{
        dictionary.clear();
        for(int i = 0; i < global::dictSize; i++) {
            dictionary[std::string(1, i)] = i;
        }
    };
    resetDictionary();

    while(ifs.read(&currChar, sizeof(currChar))){
        auto it = dictionary.find(T+currChar);
        if(it != dictionary.end()){
            T+=currChar;
        } else {
            //add T binary to queue
            try{
                bs.write(dictionary.at(T), global::maxBitLen);
            } catch(const std::exception &e){
                std::cerr << e.what() <<'\n';
            }
            dictionary.insert(std::make_pair(T+currChar, dictionary.size()));
            if(dictionary.size() >= global::maxDictSize) resetDictionary();
            T=currChar;
        }
    }
    //add T binary to queue
    try{
        bs.write(dictionary.at(T), global::maxBitLen);
    } catch(const std::exception &e){
        std::cerr << e.what() <<'\n';
    }
    bs.complete();
    ifs.close();
    std::ofstream ofs(outFile, std::ios::binary | std::ios::trunc);
    //get temporary char to write to ofs
    char bitC;
    while (bs.size() >= 8) {
        bitC = bs.read(8);
        ofs.write(&bitC, sizeof(currChar));
    }
    ofs.close();
}

void decompress(const std::string inFile, const std::string outFile){
    std::unordered_map<int, std::string> dictionary;
    bitstream bs;
    const auto resetDictionary = [&dictionary]{
        dictionary.clear();
        for(int i = 0; i < global::dictSize; i++) {
            dictionary[i] = std::string(1, i);
        }
    };
    resetDictionary();
    std::ifstream ifs(inFile, std::ios::binary);
    char currChar;
    std::string P = "";
    std::string T = "";
    while(ifs.read(&currChar, sizeof(currChar))){
        bs.write(currChar, 8);
    }
    ifs.close();
    std::ofstream ofs(outFile, std::ios::binary | std::ios::trunc);
    int bitC;
    while(bs.size() >= global::maxBitLen) {
        bitC = bs.read(global::maxBitLen);
        if(dictionary.find(bitC) != dictionary.end()){
            T = dictionary.at(bitC);
            ofs.write(T.c_str(), T.size());
            if(!P.empty()) dictionary.insert(std::make_pair(dictionary.size(), P+T.front()));
            P = T;
        } else {
            std::string tmp = P+P.front();
            if(!P.empty()) dictionary.insert(std::make_pair(dictionary.size(), tmp));
            if(bs.size() < global::maxBitLen) ofs.write(tmp.c_str(), tmp.size());
        }
        if (dictionary.size() >= global::maxDictSize) resetDictionary();
    }
    std::cout << "Output: " << ofs.tellp() << " bytes.";
    ofs.close();
}


bool compareBinaries(const std::string file1, const std::string file2){
    bitstream bs1, bs2;
    std::ifstream ifs1(file1, std::ios::binary);
    std::ifstream ifs2(file2, std::ios::binary);
    if(ifs1.tellg()!=ifs2.tellg()){
        std::cout << "Files' lengths are different.\n";
    }
    char c1, c2;
    while(ifs1.read(&c1, 1)&&ifs2.read(&c2, 1)){
        bs1.write(c1,8);
        bs2.write(c2,8);
    }
    for(int i = 0; i<bs1.size(); i++){
        if(bs1.read(8) != bs2.read(8)){
            return false;
        }
    }
    return true;
}
bool compareStrings(const std::string file1, const std::string file2){
    std::ifstream ifs1(file1, std::ios::binary);
    std::ifstream ifs2(file2, std::ios::binary);
    std::stringstream ss1, ss2;
    std::string f1, f2;
    ss1 << ifs1.rdbuf();
    f1 = ss1.str();
    ss2 << ifs2.rdbuf();
    f2 = ss2.str();
    return f1==f2;
}

double getCompRatio(const std::string &file1, const std::string &file2){
    std::ifstream ifs(file1, std::ios::binary);
    std::stringstream ss;
    std::string f1, f2;
    ss << ifs.rdbuf();
    f1 = ss.str();
    std::fstream::pos_type size1 = ifs.tellg();
    std::cout << "Input: " << size1 << " bytes.\n";
    ifs.close();
    ss.clear();
    ifs.open(file2, std::ios::binary);
    ss << ifs.rdbuf();
    f2 = ss.str();
    std::fstream::pos_type size2 = ifs.tellg();
    std::cout << "Output: " << size2 << " bytes.\n";
    return (double)size1/size2;
}

int main(int argc, char* argv[]) {
    if(argc < 4){
        std::cout << "Insufficient arguments.\n";
        return 0;
    }
    char c = argv[1][0];
    global::maxDictSize = std::stoi(argv[2]);
    global::maxBitLen = std::ceil(log2(global::maxDictSize+1));
    std::string inFile = argv[3];
    std::string outFile = "out.bin";
    switch(c){
        case 'c':
            compress(inFile, outFile);
            std::cout << "Ratio: " << std::to_string(getCompRatio(inFile, outFile));
            break;
        case 'd':
            decompress(inFile, outFile);
            break;
        default:
            std::cout << "Wrong input.\n";
            return 0;
    }
    return 0;
}


/*int main(){
    std::string outFile = "./out.bin";
    std::string inFile = "./in.bin";
    std::string file1, file2;
    std::ifstream ifs;
    std::ifstream ifs2;
    std::vector<std::vector<std::string>> graph;
    for(int i = 20; i>0; i--){
        graph.emplace_back(std::vector<std::string>());
        double comp = (double)i/10;
        std::string compS = std::to_string(comp);
        graph.back().emplace_back(compS.substr(0, 3)+"     ");
        for(int j = 0; j < 8; j++){
            graph.back().emplace_back("          ");
        }
    }
    graph.emplace_back(std::vector<std::string>());
    graph.back().emplace_back("Slovar: ");
    for(int j = 0; j < 8; j++){
        std::string slovarLen = std::to_string((int)std::pow(2, j+8));
        int slovarLenLen = slovarLen.size();
        for(int i = 0; i<10-slovarLenLen; i++){
            slovarLen+=" ";
        }
        graph.back().emplace_back(slovarLen);
    }
    for(int j = 1; j < 9; j++){
        global::maxDictSize = std::pow(2, j+7);
        global::maxBitLen = std::ceil(log2(global::maxDictSize+1));
        compress(inFile, outFile);
        decompress(outFile, "out1.bin");
        if(compareBinaries(inFile, "out1.bin")&&compareStrings(inFile, "out1.bin")){
            int index = 20 - (int)(getCompRatio(inFile, outFile)*10+0.5);
            graph[index][j] = "*         ";
        } else {
            graph[graph.size()-2][j] = "/         ";
        }

    }
    for(auto v : graph){
        for(auto s : v){
            std::cout << s;
        }
        std::cout << '\n';
    }

    return 0;
}*/