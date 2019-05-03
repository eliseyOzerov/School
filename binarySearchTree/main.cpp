/*
 * binarnoIskalnoDrevoAPS.cpp
 *
 *  Created on: Mar 27, 2019
 *      Author: ultron
 */

#include "BST.h"
#include <iostream>

bool menu(BST& bst){
    int meniIzbira;
    int vrednost;
    std::string niz;
    std::cout << "Binarno iskalno drevo - izbira: " << std::endl;
    std::cout << "1) Vnos filma" << std::endl;
    std::cout << "2) Urejen izpis filmov" << std::endl;
    std::cout << "3) Izpis povezav" << std::endl;
    std::cout << "4) Iskanje po datumu izdaje" << std::endl;
    std::cout << "5) Poisci minimum in maksimum" << std::endl;
    std::cout << "6) Poisci predhodnika in naslednika" << std::endl;
    std::cout << "7) Brisi datum" << std::endl;
    std::cout << "8) Nalaganje filmov iz datoteke" << std::endl;
    std::cout << "9) Konec" << std::endl << std::endl;
    std::cout << "Izbira: " ;
    while(!(std::cin>>meniIzbira)){
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Napacen vnos, ponovi: ";
    }
    switch(meniIzbira){
        case 1:
            std::cout << "Vnesi kljuc[int] in niz[string]: ";
            while(!(std::cin>>vrednost) || !(std::cin>>niz)){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Napacen vnos, ponovi: ";
            }
            bst.addMovie(vrednost, niz);
            break;
        case 2:
            if(bst.getRoot()== nullptr) {std::cout << "Drevo prazno." << std::endl;break;}
            std::cout << "Vse vrednosti v drevesu: " << std::endl;
            bst.printTreeOrdered(bst.getRoot());

            break;
        case 3:
            if(bst.getRoot()== nullptr) {std::cout << "Drevo prazno." << std::endl;break;}
            std::cout << "Vse povezave v drevesu: " << std::endl;
            bst.printConnections(bst.getRoot());
            break;
        case 4:
            if(bst.getRoot()== nullptr) {std::cout << "Drevo prazno." << std::endl;break;}
            std::cout << "Vnesi vrednost za iskanje: " ;
            while(!(std::cin>>vrednost)){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Napacen vnos, ponovi: ";
            }

            std::cout << "Iskana vrednost je na naslovu: " <<
            bst.search(vrednost, bst.getRoot()) << std::endl;
            break;
        case 5:
            if(bst.getRoot()== nullptr) {std::cout << "Drevo prazno." << std::endl;break;}
            std::cout << "Minimum: " << bst.getMin(bst.getRoot()) << std::endl;
            std::cout << "Maksimum: " << bst.getMax(bst.getRoot()) << std::endl;
            break;
        case 6:
            if(bst.getRoot()== nullptr) {std::cout << "Drevo prazno." << std::endl;break;}
            std::cout << "Vnesi vrednost za iskanje predhodnika in naslednika: ";
            while(!(std::cin>>vrednost)){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Napacen vnos, ponovi: ";
            }
            bst.printParentAndChildren(vrednost);
            break;
        case 7:
            if(bst.getRoot()== nullptr) {std::cout << "Drevo prazno." << std::endl;break;}
            std::cout << "Vnesi vrednost za izbris: ";
            while(!(std::cin>>vrednost)){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Napacen vnos, ponovi: ";
            }
            bst.deleteNode(vrednost);
            break;
        case 8:
            std::cout<<"Adding movies from specified file..." << std::endl;
            bst.addMoviesFromFile("C:\\Users\\Elisey\\OneDrive\\Desktop\\IMDB_date_name_mini.list");
            break;
        case 9:
            std::cout << "Program finished. Deleting tree..." << std::endl;
            bst.deleteTree(bst.getRoot());
            return false;
        default:
            std::cout << "Napacen vnos, ponovi." << std::endl;
            break;
    }
    return true;
}

int main(){
    BST bst;
    bool running = true;
    while(running){
        running = menu(bst);
    }
    return 0;
}
