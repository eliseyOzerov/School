//
// Created by Elisey on 13/05/2019.
//
#include "Huffman.h"


void Huffman::readFile(const std::string &path) {
    std::ifstream ifs(path);
    //store chars in charMap with their weights and code strings
    if(ifs){
        char c;
        while(ifs.get(c)){
            //add char to charMap
            auto it = charMap.insert(std::pair<char, std::pair<int, std::string>>(c, std::make_pair(1, "")));
            if(!it.second) {
                it.first->second.first++; //if data already existed, increment int
                for(Node* n : this->priorityQueue){
                    if(n->c == c){
                        n->weight++;
                        break;
                    }
                }
            } else {
                this->priorityQueue.push_back(new Node(c));
            }
        }
        ifs.close();
    } else {std::cout << "Error opening file.\n";}
}

Huffman::Node* Huffman::popMin() {
    Node* min = this->priorityQueue.front();
    int k;
    for(int i = 0; i<this->priorityQueue.size(); i++){
        if(this->priorityQueue[i]->weight <= min->weight){
            min = this->priorityQueue[i];
            k = i;
        }
    }
    priorityQueue.erase(priorityQueue.begin()+k);
    return min;
}

void Huffman::createEncodingTree() {
    Node* top = nullptr;
    while(this->priorityQueue.size() > 1){
        Node* right = this->popMin();
        Node* left = this->popMin();
        top = new Node();
        top->weight = right->weight + left->weight;
        top->left = left;
        top->right = right;
        this->priorityQueue.push_back(top);

    }
    this->ROOT = top;
}

void Huffman::createCodes(Node* root, std::string code) {
    if(!root) {
        std::cout << "Root is null.\n";
        return;
    }
    if(root->c != '\0'){
        /*
         * If I use this->getCharMap() instead of this->charMap, the iterator is behaving unexpectedly, why?
         */
        auto it = this->charMap.find(root->c);
        if(it != this->charMap.end()){
            it->second.second = code;
        }
        return;
    } else {
        this->createCodes(root->right, code+'1');
        this->createCodes(root->left, code+'0');
    }
}

void Huffman::decode(const std::string &in, const std::string &out) {
    std::ifstream ifs(in);
    std::ofstream ofs(out, std::ofstream::trunc);
    Node* currentNode = this->ROOT;
    if(ifs.is_open()){
        char c;
        while(ifs.get(c)){
            if(c=='1') currentNode = currentNode->right;
            else currentNode = currentNode->left;
            if(currentNode->c != '\0') {
                if(!ofs.is_open()){
                    std::cout << "Ofstream error.\n";
                    return;
                }
                ofs << currentNode->c;
                currentNode = this->ROOT;
            }
        }
    }
    ifs.close();
    ofs.close();
}

void Huffman::encode(const std::string &in, const std::string &out) {
    this->readFile(in);
    this->createEncodingTree();
    this->createCodes(ROOT, "");
    std::ifstream ifs(in);
    std::ofstream ofs(out, std::ofstream::trunc);
    if(ifs){
        char c;
        while(ifs.get(c)){
            ofs << this->charMap.find(c)->second.second;
        }
    }
    ifs.close();
    ofs.close();
}

