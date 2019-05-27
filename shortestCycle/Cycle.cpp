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

void Cycle::shortestCycle() {
    int zacVozlisce = 0;
    std::stack<std::vector<Pot*>> nivoji;
    int steviloVozlisc = this->matrikaSosednosti.size();
    //dodaj zacetne poti
    this->potiNaNivoju.clear();
    for(int i = 1; i < steviloVozlisc; i++){
        int cena = this->matrikaSosednosti[i][zacVozlisce];
        if(cena > 0){
            this->potiNaNivoju.emplace_back(new Pot(i, zacVozlisce, cena));
        }
    }
    nivoji.push(this->potiNaNivoju);
    //za vsako vozlisce razen zacetenga ustvarimo seznam poti po katerim lahko pridemo do zacetnega vozlisca
    for(int st_nivoja = 1; st_nivoja < steviloVozlisc-1; st_nivoja++){
        this->potiNaNivoju.clear();
        /*
         * ustvarili smo prvi nivo, zdaj moramo ustvariti ostale
         * moramo poiskati vse kombinacije moznih poti
         * zato gremo skozi vsa vozlisca razen zacetnega
         * in iscemo h kateri poti iz prejsnjega nivoja lahko pridruzimo trenutno vozlisce
         */
        for(Pot* zacP : nivoji.top()){
            //napravi seznam
            for(Pot* pot : nivoji.top()){
                int cena = this->matrikaSosednosti[pot->izV][zacP->izV];
                if(cena < 1) continue; //ce povezava ne obstaja ali je izV == vozlisce
                //pogledamo da trenutnega vozlisca se ni na poti - v kolikor je tako, nadaljujemo
                if(!pot->vozlNP[zacP->izV]){
                    //ker ustvarjamo nov nivo poti, ustvarimo novo pot
                    Pot* nP = new Pot(pot->izV, zacP->izV, cena + zacP->cena);
                    //kopiramo mnozico vozlisc na sprejeti poti v novo pot
                    std::copy(std::begin(pot->vozlNP), std::end(pot->vozlNP), std::begin(nP->vozlNP));
                    //dodamo trenutno vozlisce na pot
                    nP->vozlNP[zacP->izV] = true;
                    /*
                     * zdaj moramo preverit, ali ze obstaja kaksna taka pot,
                     * ki ima enak izV in mnozico vozlisc
                     * ce obstaja, uporabimo tisto, ki ima cenejso pot
                     */
                    bool obstaja = false;
                    for(Pot* p : this->potiNaNivoju){
                        if(p->izV == nP->izV && std::equal(std::begin(p->vozlNP), std::end(p->vozlNP), std::begin(nP->vozlNP))){
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
        nivoji.push(this->potiNaNivoju);
    }
    //dodamo se poti iz zacVozlisce do vseh ostalih, kjer obstaja povezava
    this->potiNaNivoju.clear();
    for(Pot* p : nivoji.top()){
        int cena = this->matrikaSosednosti[zacVozlisce][p->izV];
        if(cena > 0){
            Pot* kP = new Pot(zacVozlisce, p->izV, cena+p->cena);
            std::copy(std::begin(p->vozlNP), std::end(p->vozlNP), std::begin(kP->vozlNP));
            kP->vozlNP[p->izV] = true;
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
    nivoji.push(this->potiNaNivoju);
    std::stack<std::vector<Pot*>> kNivoji = nivoji;
    Pot* current = nivoji.top()[0];
    std::cout << "Pot je: " << current->izV + 1 << " -> ";
    nivoji.pop();
    while(!nivoji.empty()){
        for(Pot* p : nivoji.top()){
            bool arr[12];
            std::copy(std::begin(current->vozlNP), std::end(current->vozlNP), std::begin(arr));
            arr[current->vV] = false;
            if(p->izV == current->vV && std::equal(std::begin(p->vozlNP), std::end(p->vozlNP), std::begin(arr))){
                *current = *p;
                std::cout << current->izV + 1 << " -> ";
                break;
            }

        }

        nivoji.pop();
    }
    std::cout << zacVozlisce+1 << '\n';
}
