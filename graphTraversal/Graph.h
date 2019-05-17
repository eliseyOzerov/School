//
// Created by Elisey on 07/05/2019.
//

#ifndef GRAPHTRAVERSAL_GRAPH_H
#define GRAPHTRAVERSAL_GRAPH_H
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <limits>

template<typename T>
class Graph {
private:
    struct Node{
        T vrednost;
        int oddaljenost = 0; // oddaljenost od zacetnega vozlisca
        int status = 0; // status pregledanosti
        Node* predhodnik;
        std::unordered_map<Node*, int> connections;

        Node(const T &vrednost): vrednost(vrednost){}
        void setStatus(int n){
            if(status <= 2 && status>=0) status = n;
            else std::cout << "Invalid status update.\n";
        }
    };
    std::stack<Node*> stack;
    std::queue<Node*> queue;
    std::vector<Node*> nodes;
    void printPath(const T &from, const T& to);
public:
    Graph();
    ~Graph();
    Node* find(const T &value);
    Node* addNode(const T &value);
    void readGraphFromFile(const std::string &pathToFile);
    void addConnection(const T &from, const T &to, const int &cost);
    std::stack<Node*> getCurrentStack() const{return this->stack;}
    void depthSearch(const T &from, const T &to);
    void breadthSearch(const T &from, const T &to);
    bool menu(std::string folderPath);
};

template<typename T>
Graph<T>::Graph() {}

template<typename T>
Graph<T>::~Graph() {}

template<typename T>
typename Graph<T>::Node* Graph<T>::addNode(const T &value) {
    Node* n = new Node(value);
    this->nodes.push_back(new Node(value));
    return n;
}

template<typename T>
typename Graph<T>::Node* Graph<T>::find(const T &value){
    for(Graph::Node* n : this->nodes){
        if (n->vrednost == value) return n;
    }
    return nullptr;
}

template<typename T>
void Graph<T>::addConnection(const T &from, const T &to, const int &cost) {
    Node* fromT = find(from);
    Node* toT = find(to);
    if(!fromT){
        fromT = this->addNode(from);
    }
    if(!toT){
        toT = this->addNode(to);
    }
    fromT->connections.insert(std::pair<Node*, int>(find(to), cost));
    toT->connections.insert(std::pair<Node*, int>(find(from), cost));
}

template<typename T>
void Graph<T>::depthSearch(const T &from, const T &to) {
    Node* fromTemp = find(from);
    Node* toTemp = find(to);
    if(!fromTemp || !toTemp){
        std::cout << "One of the entered nodes doesn't exist.\n";
        return;
    }

    for(Node* n : this->nodes){
        n->setStatus(0);
        n->predhodnik = nullptr;
        n->oddaljenost = 0;
    }

    if(fromTemp == toTemp) return;

    fromTemp->setStatus(1);
    this->stack.push(fromTemp);

    while(this->stack.size()>0){
        Node* current = this->stack.top();
        this->stack.pop();

        for(auto p : current->connections){
            Node* n = p.first;

            if(n->status==0){
                n->setStatus(1);
                n->oddaljenost = current->oddaljenost + current->connections.find(n)->second;
                n->predhodnik = current;
                this->stack.push(n);
            }
        }

        current->setStatus(2);
    }

    this->printPath(from, to);
    std::cout << "\nCena je: " << toTemp->oddaljenost << '\n';
}

template<typename T>
void Graph<T>::breadthSearch(const T &from, const T &to) {
    Node* fromTemp = find(from);
    Node* toTemp = find(to);
    if(!fromTemp || !toTemp){
        std::cout << "One of the entered nodes doesn't exist.\n";
        return;
    }
    for(Node* n : this->nodes){
        n->setStatus(0);
        n->predhodnik = nullptr;
        n->oddaljenost = 0;
    }
    if(fromTemp == toTemp) return;
    fromTemp->setStatus(1);
    this->queue.push(fromTemp);
    while(this->queue.size()>0){
        Node* current = this->queue.front();
        this->queue.pop();
        for(auto p : current->connections){
            Node* n = p.first;
            if(n->status==0){
                n->setStatus(1);
                n->oddaljenost = current->oddaljenost + current->connections.find(n)->second;
                n->predhodnik = current;
                this->queue.push(n);
            }
        }
        current->setStatus(2);
    }
    this->printPath(from, to);
    std::cout << "\nCena je: " << toTemp->oddaljenost << '\n';
}

template<typename T>
void Graph<T>::printPath(const T &from, const T &to) {
    Node* fromTemp = find(from);
    Node* toTemp = find(to);
    if(fromTemp==toTemp){
        std::cout << "Pot je " + std::to_string(toTemp->vrednost);
        return;
    }
    if(toTemp->predhodnik == nullptr){
        std::cout << "Med " + std::to_string(fromTemp->vrednost) + " in " + std::to_string(toTemp->vrednost) + " ni poti!\n";
        return;
    } else {
        printPath(from, toTemp->predhodnik->vrednost);
        std::cout  << "->" << std::to_string(toTemp->vrednost);
    }
}

template<>
void Graph<std::string>::printPath(const std::string &from, const std::string &to) {
    Node* fromTemp = find(from);
    Node* toTemp = find(to);
    if(fromTemp==toTemp){
        std::cout << "Pot je " + toTemp->vrednost;
        return;
    }
    if(toTemp->predhodnik == nullptr){
        std::cout << "Med " + fromTemp->vrednost + " in " + toTemp->vrednost + " ni poti!\n";
        return;
    } else {
        printPath(from, toTemp->predhodnik->vrednost);
        std::cout  << "->" << toTemp->vrednost;
    }
}

template<typename T>
void Graph<T>::readGraphFromFile(const std::string &pathToFile) {
    std::ifstream ifs(pathToFile);
    int cena;
    T value1, value2;
    ifs >> cena >> cena;
    if(ifs){
        while(ifs.peek()!=EOF){
            ifs >> value1 >> value2 >> cena;
            this->addConnection(value1, value2, cena);
        }

    }
}

template<typename T>
bool Graph<T>::menu(std::string folderPath) {
    int izbira;
    std::string filepath;
    T s, d;
    std::cout << "Iskanje v globino in sirino - izbira:\n\n";
    std::cout << "1) Preberi graf iz datoteke\n";
    std::cout << "2) Pozeni iskanje v globino iz vozlisca s do d\n";
    std::cout << "3) Pozeni iskanje v sirino iz vozlisca s do d\n";
    std::cout << "4) Konec\n\n";
    std::cout << "Izbira: ";
    while(!(std::cin>>izbira)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Napacen vnos.\n";
    }
    switch(izbira){
        case 1:
            std::cout << "Vnesi naslov datoteke: ";
            std::cin >> filepath;
            this->readGraphFromFile(folderPath + filepath);
            break;
        case 2:
            std::cout << "Vnesi vozlisci s in d: ";
            std::cin >> s >> d;
            this->depthSearch(s, d);
            break;
        case 3:
            std::cout << "Vnesi vozlisci s in d: ";
            std::cin >> s >> d;
            this->breadthSearch(s, d);
            break;
        case 4:
            return false;
        default:
            std::cout << "Napacna izbira.\n";
            break;
    }
    return true;
}


#endif //GRAPHTRAVERSAL_GRAPH_H
