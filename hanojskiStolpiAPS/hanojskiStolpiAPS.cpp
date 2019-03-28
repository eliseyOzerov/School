/*
 * hanojskiStolpi.cpp
 *
 *  Created on: Mar 2, 2019
 *      Author: Elisey Ozerov
 */

#include <iostream>
#include <stack>
#include <limits>

using namespace std;

string spaces(int len, int max_len) {
	int spaces = max_len - len + 2;
	string res = "";
	for (int i = 0; i < spaces; i++) {
		res += ' ';
	}
	return res;
}

string stars(int n) {
	string res = "";
	for (int i = 0; i < n; i++) {
		res += '*';
	}
	return res;
}

void printTowers(stack<int> stacks[], int max_len) {
	stack<int> copyArr[] = { stacks[0], stacks[1], stacks[2] };

	cout << "Sklad 1" << spaces(6, max_len) << "Sklad 2" << spaces(6, max_len)
			<< "Sklad 3" << endl << endl;

	for (int i = max_len; i > 0; i--) {
		for (int j = 0; j < 3; j++) {
			if (copyArr[j].size() == i) {
				cout << stars(copyArr[j].top());
				cout << spaces(copyArr[j].top(), max_len);
				copyArr[j].pop();
			} else {
				cout << spaces(0, max_len);
			}

		}
		cout << endl;
	}

}

void move(stack<int> stacks[]) {
	int iz;
	int na;

	cout << "Vnesi stolpa \"iz\" in \"na\" locena s presledkom[1-3]: ";
	while (true) {
		if (!(cin>>iz)) {
			cout << "Napacen vnos. Ponovi izbiro: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (!(cin>>na)) {
			cout << "Napacen vnos. Ponovi izbiro: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (!(iz >= 1 && iz <= 3) || !(na >= 1 && na <= 3)) {
			cout << "Napacen vnos. Ponovi izbiro: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (stacks[iz - 1].empty()
				|| (!(stacks[na - 1].empty())
						&& stacks[iz - 1].top() > stacks[na - 1].top())) {
			cout << "Prepovedana poteza. Ponovi izbiro: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		break;
	}

	stacks[na - 1].push(stacks[iz - 1].top());
	stacks[iz - 1].pop();

}

int main() {
	int stevilo_ploscic;

	cout << "Vpisi stevilo ploscic: ";
	cin >> stevilo_ploscic;

	stack<int> s1;
	stack<int> s2;
	stack<int> s3;
	stack<int> slika;

	stack<int> stacks[] = { s1, s2, s3 };

	//fill stack1
	for (int i = stevilo_ploscic; i > 0; i--) {
		stacks[0].push(i);
		slika.push(i);
	}

	while (true) {
		if (slika == stacks[1] || slika == stacks[2]) {
			printTowers(stacks, stevilo_ploscic);
			cout << "Igra je zakljucena." << endl;
			break;
		} else {
			printTowers(stacks, stevilo_ploscic);
			move(stacks);
		}
	}

	return 0;
}

