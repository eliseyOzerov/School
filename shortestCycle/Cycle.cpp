//
// Created by Elisey on 21/05/2019.
//

#include "Cycle.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <algorithm>

void Cycle::readGraphFromFile(std::string filePath) {
    std::ifstream ifs(filePath);
    int c; // cena povezave
    int l; //stevilo vozlisc
    int i = 0; // index notranjih vektorjev
    int j = 0; // index cene povezave
    if(!this->matrikaSosednosti.empty())this->matrikaSosednosti.clear();
    if(ifs){
        ifs >> l;
        while(ifs.peek() != std::ifstream::traits_type::eof()){
            matrikaSosednosti.emplace_back(std::vector<int>());
            while(j<l){
                ifs >> c;
                matrikaSosednosti[i].push_back(c);
                j++;
            }
            i++;
            j = 0;
        }
    } else {
        std::cout << "Ifstream error.\n";
        return;
    }
}

int Cycle::shortestCycle() {
    int zacVozlisce = 0;
    std::vector<std::vector<Pot*>> nivoji;
    int steviloVozlisc = this->matrikaSosednosti.size();
    //dodaj zacetne poti
    this->potiNaNivoju.clear();
    for(int i = 1; i < steviloVozlisc; i++){
        int cena = this->matrikaSosednosti[i][zacVozlisce];
        if(cena > 0){
            this->potiNaNivoju.emplace_back(new Pot(i, zacVozlisce, cena));
        }
    }
    nivoji.push_back(this->potiNaNivoju);
    std::cout << "Dodan nivo " << nivoji.size() << " Velikost: " << nivoji.back().size() << '\n';
    //za vsako vozlisce razen zacetenga ustvarimo seznam poti po katerim lahko pridemo do zacetnega vozlisca
    for(int st_nivoja = 1; st_nivoja < steviloVozlisc-1; st_nivoja++){
        this->potiNaNivoju.clear();
        /*
         * ustvarili smo prvi nivo, zdaj moramo ustvariti ostale
         * moramo poiskati vse kombinacije moznih poti
         * zato gremo skozi vsa vozlisca razen zacetnega
         * in iscemo h kateri poti iz prejsnjega nivoja lahko pridruzimo trenutno vozlisce
         */
        for(int i = 1; i < steviloVozlisc; i++){
            //napravi seznam
            for(Pot* pot : nivoji.back()){
                int cena = this->matrikaSosednosti[i][pot->izV];
                if(cena < 1) continue; //ce povezava ne obstaja ali je izV == vozlisce
                //pogledamo da trenutnega vozlisca se ni na poti - v kolikor je tako, nadaljujemo
                if(!pot->vozlNP[i]){
                    //ker ustvarjamo nov nivo poti, ustvarimo novo pot
                    Pot* nP = new Pot(i, pot->izV, cena + pot->cena);
                    //kopiramo mnozico vozlisc na sprejeti poti v novo pot
                    nP->vozlNP |= pot->vozlNP;
                    //dodamo trenutno vozlisce na pot
                    nP->vozlNP.set(pot->izV);
                    /*
                     * zdaj moramo preverit, ali ze obstaja kaksna taka pot,
                     * ki ima enak izV in mnozico vozlisc
                     * ce obstaja, uporabimo tisto, ki ima cenejso pot
                     */
                    bool obstaja = false;
                    for(Pot* p : this->potiNaNivoju){
                        if(p->izV == nP->izV && p->vozlNP==nP->vozlNP){
                            obstaja = true;
                            if(p->cena > nP->cena){
                                *p = *nP;
                                delete nP;
                            } else {
                                delete nP;
                            }
                        }
                    }
                    if(!obstaja){
                        this->potiNaNivoju.push_back(nP);
                    }
                }
            }
        }
        nivoji.push_back(this->potiNaNivoju);
        std::cout << "Dodan nivo " << nivoji.size() << " Velikost: " << nivoji.back().size() << '\n';
    }
    //dodamo se poti iz zacVozlisce do vseh ostalih, kjer obstaja povezava
    this->potiNaNivoju.clear();
    for(Pot* p : nivoji.back()){
        int cena = this->matrikaSosednosti[zacVozlisce][p->izV];
        if(cena > 0){
            Pot* kP = new Pot(zacVozlisce, p->izV, cena+p->cena);
            kP->vozlNP |= p->vozlNP;
            kP->vozlNP.set(p->izV);
            if(!this->potiNaNivoju.empty()){
                if(this->potiNaNivoju[0]->cena > kP->cena){
                    *(this->potiNaNivoju[0]) = *kP;
                }
                delete kP;
            } else {
                this->potiNaNivoju.push_back(kP);
            }

        }
    }
    nivoji.push_back(this->potiNaNivoju);
    std::cout << "Dodan nivo " << nivoji.size() << " Velikost: " << nivoji.back().size() <<  '\n';
    std::vector<std::vector<Pot*>> kNivoji = nivoji;
    Pot* current = nivoji.back()[0];
    int cena = current->cena;
    std::cout << "Pot je: " << current->izV + 1 << " -> ";
    nivoji.erase(nivoji.end());
    while(!nivoji.empty()){
        for(Pot* p : nivoji.back()){
            std::bitset<12> bs;
            bs |= current->vozlNP;
            bs.reset(current->vV);
            if(p->izV == current->vV && bs==p->vozlNP){
                *current = *p;
                std::cout << current->izV + 1 << " -> ";
                break;
            }

        }

        nivoji.erase(nivoji.end());
    }
    std::cout << zacVozlisce+1 << '\n';
    return cena;
}
