//
// Created by Elisey on 27/05/2019.
//

#ifndef SHOPPINGLIST_INVALIDPRICE_H
#define SHOPPINGLIST_INVALIDPRICE_H

#include <iostream>
class InvalidPrice: public std::exception{
public:
const std::string msg;
InvalidPrice(std::string s):msg("InvalidPrice exception! Price: " + s + '\n'){}
~InvalidPrice(){}
const char* what() const noexcept override {
    return msg.c_str();
}
};

#endif //SHOPPINGLIST_INVALIDPRICE_H
