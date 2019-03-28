/*
 * naloga1_1PRG2.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: ultron
 */

#include <iostream>
#include <limits>

using namespace std;

int sumOfDivisorsFOR(int number) {
	int sum = 0;

	for (int i = 1; i < number; i++) {
		if (number % i == 0) {
			sum += i;
		}
	}

	return sum;
}

int sumOfDivisorsWHILE(int number) {
	int sum = 0;
	int i = 1;

	while (i < number) {
		if (number % i == 0) {
			sum += i;
		}
		i++;
	}

	return sum;
}

int sumOfDivisorsDOWHILE(int number) {
	int sum = 0;
	int i = 1;

	do {
		if (number > 0 && number % i == 0) {
			sum += i;
		}
		i++;
	} while (i < number);

	return sum;
}

void checkAbundance(int number) {
	cout << "Abundant number (for): ";
	if (sumOfDivisorsFOR(number) > number) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	cout << "Abundant number (while): ";
	if (sumOfDivisorsWHILE(number) > number) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	cout << "Abundant number (do while): ";
	if (sumOfDivisorsDOWHILE(number) > number) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

void findAllAbundantUpTo(int number) {
	cout << "All abundant up to " << number << ':' << endl;
	for (int i = 0; i < number; i++) {
		if (sumOfDivisorsFOR(i) > i) {
			cout << i << endl;
		}
	}
}

int main() {
	int number;
	int choice;

	while (true) {
		cout<< "1) Check if number abundant\n2) Find all abundant up to\n\nChoice: ";
		while (!(cin >> choice)) {
			cout << "Wrong input, try again :";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch (choice) {
		case 1:
			cout << "Enter an integer: ";
			while (!(cin >> number)) {
				cout << "Wrong input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			checkAbundance(number);
			break;
		case 2:
			cout << "Enter an integer: ";
			while (!(cin >> number)) {
				cout << "Wrong input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			findAllAbundantUpTo(number);
			break;
		default:
			cout << "Wrong input.\n";
		}
	}

	return 0;
}

