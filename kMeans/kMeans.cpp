//
// Created by Elisey on 30/05/2019.
//

#include <random>
#include <time.h>
#include <sstream>
#include <algorithm>
#include "kMeans.h"

namespace global{
    std::string empty = "   ";
    std::vector<std::string> clusters = {" ! ", " _ ", " > ", " @ ", " = ", " % ", " $ ", " ? ", " # ", " ~ "};

}

double kMeans::getDistance(Tocka* a, Tocka* b){
    if(!a || !b) return -1;
    return std::sqrt(std::pow(a->x - b->x, 2) + std::pow(a->y - b->y, 2));
}

void kMeans::readData(const std::string &path){
    std::ifstream ifs(path);

    if(!ifs){
        std::cout << "Error opening file.\n";
        return;
    }
    double x, y;
    int i = 0;
    while(ifs.peek() != EOF){
        ifs >> x >> y;
        this->rawData.emplace_back(new Tocka(i, x, y, nullptr));
        i++;
    }

    this->setRanges();

    std::mt19937 mt(time(nullptr));
    std::uniform_real_distribution<double> distX(this->xMin, this->xMax);
    std::uniform_real_distribution<double> distY(this->yMin, this->yMax);

    //ustvari nove centre
    for(int i = 0; i < this->stGruc; i++){
        Tocka* center = new Tocka(-1, i+(7*(i+1)), i+(7*(i+1)), nullptr);
        Gruca* iG = new Gruca(i, center);
        center->gruca = iG;
        this->gruce.emplace_back(iG);
    }
}

void kMeans::assignPointsToClusters() {
    if(this->rawData.empty()){
        std::cout << "Ni podatkov.\n";
        return;
    }
    for(Tocka* t : this->rawData){
        Gruca* tGruca = this->gruce.front();
        for(Gruca* g : this->gruce){
            if(this->getDistance(t, g->center) < this->getDistance(t, tGruca->center)){
                tGruca = g;
            }
        }
        if(t->gruca){
            t->gruca->tocke.erase(t);
        }
        tGruca->tocke.insert(t);
        t->gruca = tGruca;
    }
}

double deli(std::vector<double>& v, int dno, int vrh){
    double pivot = v[dno];
    int dn = dno;
    int vr = vrh;
    while(vr>dn){
        while(v[dn] <= pivot && dn < vrh){
            dn++;
        }
        while(v[vr] >= pivot && vr > dno){
            vr--;
        }
        if(vr > dn){
            std::swap(v[dn], v[vr]);
        }
    }
    std::swap(v[dno], v[vr]);
    return vr;
}

void quickSort(std::vector<double>& v, int dno, int vrh){
    if(dno < vrh){
        int j = deli(v, dno, vrh);
        quickSort(v, dno, j-1);
        quickSort(v, j+1, vrh);
    }
}
/*
 * kMeans centers
 */
/*void kMeans::newClusterCenters() {
    for(Gruca* g : this->gruce){
        double x = 0;
        double y = 0;
        if(g->tocke.empty())continue;
        for(Tocka* t: g->tocke){
            x+=t->x;
            y+=t->y;
        }
        g->center->x = x/g->tocke.size();
        g->center->y = y/g->tocke.size();

    }
}*/
/*
 * kMedians centers
 * Ustvarim dva vektorja - z X in Y koordinatami vhodnih tock
 * Za vsako gruco spraznim vektorja,
 * za vsako tocko v gruci dobim koordinate in jih potisnem v pravi vektor,
 * sortiram vektorja,
 * ce je velikost vektorja liha,
 * dobimo index mediane tako, da odstejemo ena od velikosti vektorja in delimo z dva,
 * ce pa je soda, vzamemo povprecje dveh sredinskih vrednosti - prvo dobimo tak, da delimo
 * velikost vektorja z dva in odstejemo ena, ker se indexi zacnejo z 0, za drugo pa samo delimo velikost z 2
 */
void kMeans::newClusterCenters() {
    std::vector<double> tockeX;
    std::vector<double> tockeY;
    for(Gruca* g : this->gruce){
        int tSize = g->tocke.size();
        tockeX.clear();
        tockeY.clear();
        if(!tSize)continue;
        for(Tocka* t: g->tocke){
            tockeX.push_back(t->x);
            tockeY.push_back(t->y);
        }
        quickSort(tockeX, 0, tockeX.size()-1);
        quickSort(tockeY, 0, tockeY.size()-1);
        if(tSize & 1){
            g->center->x = tockeX[(tSize-1)/2];
            g->center->y = tockeY[(tSize-1)/2];
        } else {
            g->center->x = (tockeX[tSize/2-1]+tockeX[tSize/2])/2;
            g->center->y = (tockeY[tSize/2-1]+tockeY[tSize/2])/2;
        }

    }
}

void kMeans::fillGraph(){
    if(!this->yMax || !this->xMax) return;
    for(int i = 0; i < std::ceil(this->yMax); i++){
        this->graph.emplace_back(std::vector<std::string>());
        for(int j = 0; j < std::ceil(this->xMax); j++){
            this->graph[i].emplace_back(global::empty);
        }
    }
    for(Tocka* t : this->rawData){
        this->graph[std::ceil(t->y)-1][std::ceil(t->x)-1] = global::clusters[t->gruca->index];
    }
    for(Gruca* g : this->gruce){
        this->graph[std::ceil(g->center->y)-1][std::ceil(g->center->x)-1] = ' ' + std::to_string(g->index) + ' ';
    }
}

void kMeans::printGraph(){
    fillGraph();
    std::stringstream ss;
    for(const auto &v : this->graph){
        ss << '\\';
        for(const auto &c : v){
            ss << c;
        } ss << "\\\n";
    }
    std::cout << ss.str() << "\n\n";
}

void kMeans::createRandomData(int stTock) {
    std::mt19937 mt(time(nullptr));
    std::uniform_real_distribution<double> dist(0.1, 29.9);

    for(Tocka* t : this->rawData) delete t;
    for(Gruca* g : this->gruce) delete g;

    this->rawData.clear();
    this->gruce.clear();


    //fill vector of points
    for(int i = 0; i < stTock; i++){
        Tocka* nT = new Tocka(i, dist(mt), dist(mt), nullptr);
        this->rawData.emplace_back(nT);
    }

    //create new centers
    for(int i = 0; i < this->stGruc; i++){
        Tocka* center = new Tocka(-1, dist(mt), dist(mt), nullptr);
        Gruca* iG = new Gruca(i, center);
        center->gruca = iG;
        this->gruce.emplace_back(iG);
    }

}

void kMeans::printPoints(std::ofstream &ofs) {
    for(Tocka* t : this->rawData){
        ofs << t->index << ' ';
        if(t->gruca) ofs << t->gruca->index << '\n';
        else ofs << -1 << '\n';
    }
    ofs.close();
}

void kMeans::setRanges() {
    if(this->rawData.empty()){
        std::cout << "Ni podatkov.\n";
        return;
    }
    this->xMin = this->rawData.front()->x;
    this->xMax = this->rawData.back()->x;
    this->yMin = this->rawData.front()->y;
    this->yMax = this->rawData.back()->y;
    for(Tocka* t : this->rawData){
        if(t->x < xMin) xMin = t->x;
        if(t->y < yMin) yMin = t->y;
        if(t->x > xMax) xMax = t->x;
        if(t->y > yMax) yMax = t->y;
    }
}
