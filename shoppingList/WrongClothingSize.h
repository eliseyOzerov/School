//
// Created by Elisey on 27/05/2019.
//

#ifndef SHOPPINGLIST_WRONGCLOTHINGSIZE_H
#define SHOPPINGLIST_WRONGCLOTHINGSIZE_H


#include <string>
#include <exception>

class WrongClothingSize: public std::exception {
public:
const std::string msg;
WrongClothingSize(std::string s):msg("WrongClothingSize exception! Size: " + s + '\n'){}
~WrongClothingSize(){}
const char* what() const noexcept override{
    return msg.c_str();
}
};


#endif //SHOPPINGLIST_WRONGCLOTHINGSIZE_H
