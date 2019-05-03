//
// Created by Elisey on 03/04/2019.
//

#ifndef KMPSEARCH_TEXTFILE_H
#define KMPSEARCH_TEXTFILE_H
#include <vector>
#include <string>

class TextFile {
private:
    std::vector<unsigned char> file;
public:
    //Constructors
    TextFile();
    TextFile(std::string text);
    //Destructor
    ~TextFile();
    //Getters & Setters
    std::vector<unsigned char> getTextFile();
    void setTextFile(std::string text);
    //Search functions
    std::vector<unsigned int> kmpSearch(const std::string pattern);
};


#endif //KMPSEARCH_TEXTFILE_H
