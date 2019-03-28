/*
 * clothing.h
 *
 *  Created on: Mar 13, 2019
 *      Author: ultron
 */

#ifndef CLOTHING_H_
#define CLOTHING_H_
#include <string>

class Clothing {
  private:
    int gender;
    int size;
    double price;
    int quantity;
    std::string name;
    static double discount;
    static int count;
  public:

    Clothing();
    Clothing(const Clothing& clothing);
    Clothing(int gender, int size, double price, int quantity, std::string name);
    ~Clothing();

    int getGender(){return this->gender;}
    int getSize(){return this->size;}
    std::string getName(){return this->name;}
    double getPrice(){return this->price;}
    int getQuantity(){return this->quantity;}
    static double getDiscount(){return discount;}
    void setGender(int gender);
    void setSize(int size);
    void setName(std::string name);
    void setPrice(double price);
    void setQuantity(int quantity);
    void print();
    std::string toString();
    double getTotalPrice();
};

#endif
