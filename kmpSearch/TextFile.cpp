//
// Created by Elisey on 03/04/2019.
//

#include "TextFile.h"
#include <vector>
#include <string>
#include <iostream>
#include <bits/ios_base.h>
#include <fstream>
#include <sstream>
#include <exception>

TextFile::TextFile() {}
TextFile::TextFile(std::string path) {
    std::ifstream ifs (path, std::ifstream::in);
    if(ifs.is_open()){
        std::stringstream ss;
        ss << ifs.rdbuf();
        this->file = ss.str();
        ifs.close();
    } else {
        std::cout << "Ifstream error.\n";
    }

}
TextFile::~TextFile() {}

std::string TextFile::getTextFile(){
    return this->file;
}

void TextFile::setTextFile(std::string path){
    std::ifstream ifs (path, std::ifstream::in);
    if(ifs.is_open()){
        std::stringstream ss;
        ss << ifs.rdbuf();
        this->file = ss.str();
        ifs.close();
    } else {
        std::cout << "Ifstream error.\n";
        return;
    }

}

std::vector<unsigned int> TextFile::kmpSearch(const std::string pattern){
    //Priprava tabele

    int size = pattern.size();
    std::vector<int> kmpNext(size); //vektor za tabelo
    int j = 0; //konec prefixa
    int i; //konec sufixa
    kmpNext[0] = -1;
    kmpNext[1] = 0;
    for (i = 2; i < size; i++) {
        /*
         * Primerjamo crke na kmpNext[j] in kmpNext[i-1]
         * V kolikor sta enaki, povecamo oba indeksa
         * V kolikor nista, zmanjsujemo j za 1 dokler ni enak nic
         * (Ker smo ze primerjali vse prejsnje crke, lahko zmanjsujemo j za ena.
         * Tako vidimo, ali je konec trenutnega sufixa enak koncu katerega od prejsnjih prefixov,
         * kar pomeni, da imamo ponavljanje obstojecega prefixa, in zapisemo njegovo dolzino v kmpNext[i]
         */
        while (j > 0 && pattern[j] != pattern[i-1])
            j = kmpNext[j];

        if (pattern[j] == pattern[i-1])
            j++;
        kmpNext[i] = j;
    }

    //Iskanje
    int iB = 0; //indeks crke besedila
    int iVz = 0; //indeks crke vzorca
    std::vector<unsigned int> results; //vektor z indeksi besedila, kjer se pojavlja vzorec

    while(iB < (this->file.size() - pattern.size()+1)){
        if(this->file[iB] == pattern[iVz]){
            if(iVz == pattern.size()-1){
                results.push_back(iB-iVz);
                iVz = 0;
            } else {
                iVz++;
            }
            iB++;
        } else {
            if(iVz == 0){
                iB++;
            } else {
                iVz-=iVz-kmpNext[iVz];
            }
        }
    }

    return results;
}