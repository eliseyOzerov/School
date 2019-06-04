/*
 * naloga1_2PRG2.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: ultron
 */
#include "PersonWeight.h"
#include <iostream>
#include <limits>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;

const int n = 30;

char menu() {

	cout << "Menu\n";
	cout << "=========\n";
	cout << "1 ... GENERATE WEIGHTS\n";
	cout << "2 ... AVERAGE WEIGHT\n";
	cout << "3 ... DAYS ABOVE AVERAGE\n";
	cout << "4 ... MIN WEIGHT\n";
	cout << "5 ... CALCULATE BMI\n";
	cout << "6 ... CHECK MONTH\n";
	cout << "7 ... CHECK DAY\n";
	cout << "8 ... EXIT\n";
	cout << "=========\n";
	cout << "Select: ";

	string selection;
	do
	{
		if (!getline(cin, selection))
		{
			return 0;
		}
	}while (selection.length() == 0);
	return selection[0];
}

void generateWeights(vector<PersonWeight*> &weights) {
	random_device rd;
	default_random_engine gen(rd());
	uniform_real_distribution<double> dist(-2.0, 2.0);
	for(unsigned int i = 0; i<weights.size(); i++){
		weights[i] = new PersonWeight(1, i+1, 80 + dist(gen));
	}
}

void printArray(vector<PersonWeight*> &weights) {
	for (unsigned int index = 0; index < weights.size(); index++) {
		cout << weights[index]->toString() << endl;
	}
}

double averageWeight(vector<PersonWeight*> &weights){
	double avg = 0;
	for(unsigned int i = 0; i<weights.size(); i++){
		avg+=weights[i]->getWeight();
	}
	avg = avg/weights.size();
	return avg;
}

void daysAboveAverage(vector<PersonWeight*> &weights, double average){
	int above_avg = 0;
	cout << "Days above average: ";
	for(unsigned int i = 0; i<weights.size(); i++){
		if(weights[i]->getWeight()>average){
			above_avg++;
		}
	}
	cout << above_avg << endl;
}

double minWeight(vector<PersonWeight*> &weights){
	double min = weights[0]->getWeight();
	for(unsigned int i = 1; i<weights.size(); i++){
		if(weights[i]->getWeight()<min){
			min = weights[i]->getWeight();
		}
	}

	return min;
}

void calcBMI(vector<PersonWeight*> &weights){
	double height;
	cout << "Vnesi visino[m]";
	while(!(cin>>height)){
		cout << "Wrong input, try again :";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "BMIs: ";

	for(unsigned int i=0; i<weights.size(); i++){
		cout << weights[i]->getWeight()/(height*height) << ' ';
	}
}

/*int main(int argc, char *argv[]) {
	bool running = true;
	bool generated = false;
	char izbira;
	vector<PersonWeight*> weights(n);
	srand (time(NULL));
	do {

		izbira = menu();
		switch (izbira) {
		case '1':
			generateWeights(weights);
			generated = true;
			cout << "Weight array: " << endl;
			printArray(weights);
			cout << endl;
			break;
		case '2':
			if(generated){
				cout.precision(1);
				cout << "Average weight: " << fixed << averageWeight(weights) << "kg" << endl;
			} else {
				cout << "Array empty." << endl;
			}

			break;
		case '3':
			if(generated){
				daysAboveAverage(weights, averageWeight(weights));
			} else {
				cout << "Array empty." << endl;
			}

			break;
		case '4':
			if(generated){
				cout.precision(1);
				cout << "Min weight: " << fixed << minWeight(weights) << "kg" << endl;
			} else {
				cout << "Array empty." << endl;
			}

			break;
		case '5':
			if(generated){
				calcBMI(weights);
			} else {
				cout << "Array empty." << endl;
			}

			break;
		case '6':
			if(weights[0]->isFirst(1)){
				cout << "Is first.";
			} else {
				cout << "Isn't first.";
			}
			break;
		case '7':
			if(weights[0]->isJanuary(1)){
				cout << "Is first.";
			} else {
				cout << "Isn't first.";
			}
			break;
		case '8':
			running = false;
			break;
		default:
			cout << "Wrong selection!\n";
		}
	} while (running);

	return 0;
}*/

int main(){
    std::string filename = "";
}