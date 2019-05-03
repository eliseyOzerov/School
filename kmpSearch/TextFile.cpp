//
// Created by Elisey on 03/04/2019.
//

#include "TextFile.h"
#include <vector>
#include <string>
#include <iostream>

TextFile::TextFile() {}
TextFile::TextFile(std::string text) {
    std::copy(text.begin(), text.end(), std::back_inserter(this->file));
}
TextFile::~TextFile() {}

std::vector<unsigned char> TextFile::getTextFile(){
    return this->file;
}

void TextFile::setTextFile(std::string text){
    std::copy(text.begin(), text.end(), std::back_inserter(this->file));
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
         * V kolikor sta enaki, povecamo ob indeksa
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

}