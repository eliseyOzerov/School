/*
 * PersonWeight.h
 *
 *  Created on: Mar 13, 2019
 *      Author: ultron
 */



#ifndef PERSON_WEIGHT_H_
#define PERSON_WEIGHT_H_
#include <string>

class PersonWeight{
private:
	int month;
	int day;
	double weight;
	static bool gender;
public:
	PersonWeight();
	PersonWeight(const PersonWeight& pw);
	PersonWeight(int month, int day, double weight);
	~PersonWeight();

	void setMonth(int month);
	void setDay(int day);
	void setWeight(double weight);
	int getMonth();
	int getDay();
	double getWeight();
	std::string toString();
	static bool isJanuary(int month);
	static bool isFirst(int day);
};

#endif
