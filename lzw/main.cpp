#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <fstream>
#include <queue>

namespace global {
    const int dictSize = 256;
    const int maxBitLen = std::ceil(log2(dictSize+1));
    const int maxDictSize = std::pow(2, maxBitLen);
}

void compress(std::ifstream &ifs, std::ofstream &ofs){
    if(ifs.fail()) {
        std::cout << "Couldn't open input file.\n";
        return;
    }
    if(ofs.fail()){
        std::cout << "Couldn't open output file.\n";
        return;
    }

    std::string T = "";
    std::unordered_map<std::string, unsigned int> dictionary;
    std::queue<bool> bitQueue;

    const auto resetDictionary = [&dictionary]{
        dictionary.clear();
        for(int i = 0; i < global::dictSize; i++) {
            dictionary[std::string(1, i)] = i;
        }
    };
    resetDictionary();

    char c;
    while(ifs.get(c)){
        auto it = dictionary.find(T+c);
        if(it != dictionary.end()){
            T+=c;
        } else {
            //add T binary to queue
            for(unsigned int i = 0; i < global::maxBitLen; i++){
                bitQueue.push((dictionary.at(T) >> i) & 0x1);
            }
            //get temporary char to write to ofs
            char bitC;
            while(bitQueue.size() >= 8){
                bitC = 0;
                for(unsigned int j = 0; j < 8; j++){
                    bitC <<= true;
                    bitC |= bitQueue.front();
                    bitQueue.pop();
                }
            }
            ofs.write(&bitC, true);
            //if this was the last char, create one last char from queue
            if(ifs.peek() == EOF){
                bitC = 0;
                for(unsigned int j = 0; j < bitQueue.size(); j++){
                    bitC <<= true;
                    bitC |= bitQueue.front();
                    bitQueue.pop();
                }
                for(unsigned int j = 0; j < 8-bitQueue.size(); j++){
                    bitC <<= true;
                }
                ofs.write(&bitC, true);
            }
            dictionary[T+c] = dictionary.size();
            if(dictionary.size() == global::maxDictSize) resetDictionary();
            T=c;
        }
    }
}

void decompress(std::ifstream &ifs, std::ofstream &ofs){
    if(ifs.fail()) {
        std::cout << "Input failed.\n";
        return;
    }
    if(ofs.fail()){
        std::cout << "Output failed.\n";
        return;
    }
    std::unordered_map<unsigned int, std::string> dictionary;
    const auto resetDictionary = [&dictionary]{
        dictionary.clear();
        for(int i = 0; i < global::dictSize; i++) {
            dictionary[i] = std::string(1, i);
        }
    };
    resetDictionary();

    unsigned int c;
    std::string P = "";
    std::string T = "";
    while(ifs.read(reinterpret_cast<char*>(&c), global::maxBitLen)){
        if(dictionary.size() == global::maxDictSize) resetDictionary();
        if(dictionary.find(c) != dictionary.end()){
            dictionary[c] = P + P.front();
        }
        T = dictionary[c];
        dictionary[dictionary.size()] = P+T.front();
        P = T;
        ofs << T;
    }
}

int main() {
    std::string folderpath = "C:\\Users\\Elisey\\OneDrive\\Documents\\GitHub\\school\\lzw\\";
    std::ifstream ifs(folderpath+"in.txt");
    std::ofstream ofs(folderpath+"out.bin", std::ios::binary|std::ios::trunc);
    compress(ifs, ofs);
    ifs.close();
    ofs.close();
    /*ifs.open(folderpath+"out.bin", std::ios::binary);
    ofs.open(folderpath+"out_d.txt", std::ios::trunc);
    decompress(ifs, ofs);
    ifs.close();
    ofs.close();*/
    return 0;
}