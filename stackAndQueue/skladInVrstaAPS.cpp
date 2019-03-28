/*
 * skladInVrsta.cpp
 *
 *  Created on: Mar 1, 2019
 *      Author: Elisey Ozerov
 */

#include <iostream>
#include <limits>

using namespace std;

class Stack {
public:
	int top = -1;
	int max_size = 0;
	int * container;

	//Constructors & destructor

	Stack(int size) {
		max_size = size;
		container = new int[size];
	}
	Stack() {
		max_size = 100;
		container = new int[100];
	}
	~Stack() {
		delete[] container;
	}

	//Member functions
	void push(int data) {
		top++;
		if (top < max_size) {
			container[top] = data;
		} else {
			cout << "Sklad poln." << endl;
			top--;
		}
		return;
	}

	int pop() {
		if (top > -1) {
			int tmp = container[top];
			container[top] = NULL;
			top--;
			return tmp;
		} else {
			cout << "Sklad prazen." << endl;
			return 0;
		}

	}

	void outputStack() {
		if (top > -1) {
			for (int i = 0; i <= top; i++) {
				cout << container[i] << ' ';
			}
		} else {
			cout << "Sklad prazen." << endl;
		}
		return;
	}

};

class Queue {

public:

	int max_size;
	int head = 0;
	int tail = 0;
	int * container;

	//Constructors & destructor
	Queue(int size) {
		max_size = size;
		container = new int[size];
	}
	Queue() {
		max_size = 100;
		container = new int[100];
	}
	~Queue() {
		delete[] container;
	}

	//Member functions
	void append(int data) {
		int new_tail;
		if (tail < max_size - 1) {
			new_tail = (tail % max_size) + 1;
		} else {
			new_tail = 0;
		}

		if (new_tail == head) {
			cout << "Vrsta polna." << endl;
		} else {
			container[tail] = data;
			tail = new_tail;
		}
		return;
	}

	int read() {
		if (head == tail) {
			cout << "Vrsta prazna." << endl;
			return 0;
		} else {
			int tmp = container[head];
			head = (head % max_size) + 1;
			return tmp;
		}
	}

	void outputQueue() {
		if (head == tail) {
			cout << "Vrsta prazna." << endl;
		} else {
			int next = head;
			while (next != tail) {
				cout << container[next] << ' ';
				next = ((next+1) % max_size);
			}
		}
		return;
	}
};

int main() {
	int max = 100;
	int izbira;
	int podatek;
	bool running = true;

	cout << "Vnesite velikost polj MAX[int]: ";
	while (!(cin >> max)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Napacen vnos. Ponovi vnos: ";

	}

	cout << endl << endl;

	Stack* s = new Stack(max);
	Queue* q = new Queue(max);

	while (running) {
		cout << "Sklad izbira:\n"
				"1)Vnos podatka\n"
				"2)Branje podatka\n"
				"3)Izpis vsebine sklada\n\n"
				"Krozna vrsta - izbira:\n"
				"4)Vnos podatka\n"
				"5)Branje podatka\n"
				"6)Izpis vrste od glave do repa\n\n"
				"7)Konec: 7\n\n"
				"Izbira: ";

		while (!(cin >> izbira)) {
			cout << "Napacen vnos.\nPonovite izbiro: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max());
		}

		cout << endl << endl;

		switch (izbira) {
		case 1:
			cout << "Vnesite podatek[int]: ";
			while (!(cin >> podatek)) {
				cout << "Napacen vnos.\nVnesite podatek ponovno: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
			}
			s->push(podatek);
			cout << endl;
			break;
		case 2:
			if (int n = s->pop()) {
				cout << "Podatek: " << n << endl;
			}

			break;
		case 3:
			cout << "Sklad: ";
			s->outputStack();
			cout << endl;
			break;
		case 4:
			cout << "Vnesite podatek[int]: ";
			while (!(cin >> podatek)) {
				cout << "Napacen vnos.\nVnesite podatek ponovno: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max());
			}
			q->append(podatek);
			cout << "Head: " << q->head << " Tail: " << q->tail << endl;
			break;
		case 5:
			cout << "Prebran podatek: " << q->read() << endl;
			cout << "Head: " << q->head << " Tail: " << q->tail << endl;
			break;
		case 6:
			cout << "Vrsta: ";
			q->outputQueue();
			cout << "Head: " << q->head << " Tail: " << q->tail << endl;
			cout << endl;
			break;
		case 7:
			cout << "Konec." << endl;
			running = false;
			break;
		default:
			cout << "Napacen vnos.\nPonovite izbiro: ";
			break;
		}
	}
	delete s;
	delete q;
	return 0;
}

