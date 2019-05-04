//
// Created by Elisey on 03/04/2019.
//

#ifndef KMPSEARCH_TEXTFILE_H
#define KMPSEARCH_TEXTFILE_H
#include <vector>
#include <string>

class TextFile {
private:
    std::string file;
public:
    //Constructors
    TextFile();
    TextFile(std::string path);
    //Destructor
    ~TextFile();
    //Getters & Setters
    std::string getTextFile();
    void setTextFile(std::string path);
    //Search functions
    std::vector<unsigned int> kmpSearch(const std::string pattern);
};


#endif //KMPSEARCH_TEXTFILE_H
