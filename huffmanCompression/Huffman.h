//
// Created by Elisey on 13/05/2019.
//

#ifndef HUFFMANCOMPRESSION_HUFFMAN_H
#define HUFFMANCOMPRESSION_HUFFMAN_H
#include <vector>
#include <fstream>
#include <queue>
#include <iostream>
#include <unordered_map>

class Huffman {
private:
    struct Node{
        char c;
        int weight = 1;
        Node* right = nullptr;
        Node* left = nullptr;
        Node()=default;
        Node(char c): c(c){}
    };
    Node* ROOT;
    std::vector<Node*> priorityQueue;
    std::unordered_map<char, std::pair<int, std::string>> charMap;
    Node* popMin();
    void createCodes(Node* root, std::string code);
    void createEncodingTree();
    void readFile(const std::string &path);
public:
    void encode(const std::string &in, const std::string &out);
    void decode(const std::string &in, const std::string &out);
};


#endif //HUFFMANCOMPRESSION_HUFFMAN_H
