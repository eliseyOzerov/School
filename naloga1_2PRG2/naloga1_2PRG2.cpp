/*
 * naloga1_2PRG2.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: ultron
 */

#include <iostream>
#include <limits>
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
	cout << "6 ... EXIT\n";
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

void generateWeights(double weights[], int n) {
	for (int index = 0; index < n; index++) {
		weights[index] = ((rand() % 110) + 750) / 10.0;
	}
}

void printArray(double weights[], int n) {
	for (int index = 0; index < n; index++) {
		cout.precision(1);
		cout << fixed << weights[index] << "\t";
	}
}

double averageWeight(double weights[], int arr_size){
	double avg = 0;
	for(int i = 0; i<arr_size; i++){
		avg+=weights[i];
	}
	avg = avg/arr_size;
	return avg;
}

void daysAboveAverage(double weights[], double average, int arr_size){
	int above_avg = 0;
	cout << "Days above average: ";
	for(int i = 0; i<arr_size; i++){
		if(weights[i]>average){
			above_avg++;
		}
	}
	cout << above_avg << endl;
}

double minWeight(double weights[], int arr_size){
	double min = weights[0];
	for(int i = 1; i<arr_size; i++){
		if(weights[i]<min){
			min = weights[i];
		}
	}

	return min;
}

void calcBMI(double weights[], int arr_size){
	double height;
	cout << "Vnesi visino[double]";
	while(!(cin>>height)){
		cout << "Wrong input, try again :";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "BMIs: ";

	for(int i=0; i<arr_size; i++){
		cout << weights[i]/(height*height) << ' ';
	}
}

int main(int argc, char *argv[]) {
	bool running = true;
	bool generated = false;
	char izbira;
	double weights[n];
	srand (time(NULL));
	do {

		izbira = menu();
		switch (izbira) {
		case '1':
			generateWeights(weights, n);
			generated = true;
			cout << "Age array: " << endl;
			printArray(weights, n);
			cout << endl;
			break;
		case '2':
			if(generated){
				cout.precision(1);
				cout << "Average weight: " << fixed << averageWeight(weights, n) << endl;
			} else {
				cout << "Array empty." << endl;
			}

			break;
		case '3':
			if(generated){
				daysAboveAverage(weights, averageWeight(weights, n), n);
			} else {
				cout << "Array empty." << endl;
			}

			break;
		case '4':
			if(generated){
				cout.precision(1);
				cout << "Min weight: " << fixed << minWeight(weights, n) << endl;
			} else {
				cout << "Array empty." << endl;
			}

			break;
		case '5':
			if(generated){
				calcBMI(weights, n);
			} else {
				cout << "Array empty." << endl;
			}

			break;
		case '6':
			running = false;
			break;
		default:
			cout << "Wrong selection!\n";
		}
	} while (running);

	return 0;
}




