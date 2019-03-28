/*
 * DoublyLinkedListAPS.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: ultron
 */

#include <iostream>
#include <limits>
#include <chrono>
#include <fstream>
using namespace std;

class DLL{

private:

	struct Node{

		int key;

	public:
		Node* next = NULL;
		Node* prev = NULL;

		Node(int key){
			this->key = key;
		}

		int getKey(){
			return this->key;
		}
	};

	Node* HEAD = NULL;
	Node* TAIL = NULL;

public:



	Node* getHead(){
		return this->HEAD;
	}

	Node* getTail(){
		return this->TAIL;
	}

	void insertAtHead(int n){
		Node* node = new Node(n);
		node->next = this->HEAD;
		this->HEAD = node;
		if(!this->TAIL){
			this->TAIL = node;
		}
		if(node->next){
			node->next->prev = node;
		}
	}

	void insertAtTail(int n){
		Node* node = new Node(n);
		node->prev = this->TAIL;
		this->TAIL = node;
		if(!this->HEAD){
			this->HEAD = node;
		}
		if(node->prev){
			node->prev->next = node;
		}
	}

	Node* search(int key){
		cout << "Iskanje podatka..." << endl;
		Node* HEAD = this->HEAD;

		if(!HEAD){
			cout << "Seznam prazen." << endl;
			return NULL;
		} else {
			Node* current = HEAD;

			while(current){
				if(current->getKey()!=key){
					if(current->next){
						current = current->next;
					} else {
						cout << "Kljuc ni bil najden." << endl;
						return NULL;
					}
				} else {
					cout << "Kljuc najden." << endl;
					return current;
				}
			}
			cout << "Napaka." << endl;
			return NULL;
		}

	}

	void insertAfter(int key, int before_key){
		Node* location = search(before_key);
		Node* node = new Node(key);
		if(location){
			node->prev = location;
			node->next = location->next;
			if(location->next){
				location->next->prev = node;
			} else {
				this->TAIL = node;
			}

			location->next = node;
		} else {
			return;
		}
	}

	void clearList(){
		Node* current = this->HEAD;

		while(current){
			delete current;
			if(current->next){
				current = current->next;
			} else {
				this->HEAD = NULL;
				this->TAIL = NULL;
				cout << "Seznam prazen." << endl;
				break;
			}
		}
	}

	void deleteNode(int n){
		Node* nodeToDelete = search(n);

		if(nodeToDelete){
			if(nodeToDelete->prev){
				nodeToDelete->prev->next = nodeToDelete->next;
			} else {
				this->HEAD = nodeToDelete->next;
			}
			if(nodeToDelete->next){
				nodeToDelete->next->prev = nodeToDelete->prev;
			} else {
				this->TAIL = nodeToDelete->prev;
			}

			delete nodeToDelete;
			cout << "Kljuc izbrisan." << endl;
		}
	}

	void printList(){
		Node* current = this->HEAD;

		if(!current){
			cout << "Seznam prazen." << endl;
		} else {
			cout << "HEAD -> ";
			while(current){
				cout << current->getKey() << ' ';
				current = current->next;
			}
			cout << "<- TAIL" << endl;
		}
	}

	void printReverse(){
		Node* current = this->TAIL;

		if(!current){
			cout << "Seznam prazen." << endl;
		} else {
			cout << "TAIL -> ";
			while(current){
				cout << current->getKey() << ' ';
				current = current->prev;
			}
			cout << "<- HEAD" << endl;
		}
	}

	long long sum(){
		Node* current = this->HEAD;
		long long sum = 0;
		while(current){
			sum += current->getKey();
			current = current->next;
		}
		return sum;
	}

};

int input(){
	int podatek;
	while(!(cin>>podatek)){
		cout << "Napacen vnos, ponovi: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return podatek;
}

string inputAtListHead(DLL* dll, int N){
	string res;
	dll->clearList();
	auto start = chrono::steady_clock::now();
	for(int i = 1; i <= N; i++){
		dll->insertAtHead(i);
	}
	auto end = chrono::steady_clock::now();
	res = "Vnos v glavo seznama (N elementov): " +
			to_string(std::chrono::duration_cast<chrono::microseconds>(end-start).count())+
			" us.\n";
	return res;
}

string inputAtFirstIofArray(int* polje, int N){
	string res;
	auto start = chrono::steady_clock::now();
	for(int i = 1; i <= N; i++){
		for(int j = N-1; j>0; j--){
			polje[j] = polje[j-1];
		}
		polje[0] = i;
	}
	auto end = chrono::steady_clock::now();
	res = "Vnos na prvo mesto polja (N elementov): " +
			to_string(chrono::duration_cast<chrono::microseconds>(end-start).count())+
			" us.\n";
	return res;
}

string inputAtEndOfArray(int* polje, int N){
	string res;
	auto start = chrono::steady_clock::now();
	for(int i = 1; i <= N; i++){
		polje[i-1] = i;
	}
	auto end = chrono::steady_clock::now();
	res = "Vnos na konec polja (N elementov): " +
			to_string(chrono::duration_cast<chrono::microseconds>(end-start).count())+
			" us.\n";

	return res;
}

string sumOfListValues(DLL* dll){
	string res, sum;
	auto start = chrono::steady_clock::now();
	sum = to_string(dll->sum());
	auto end = chrono::steady_clock::now();
	res = "Vsota vrednosti seznama: " + sum + " \nSestevanje vrednosti kljucev seznama (N elementov): " +
			to_string(chrono::duration_cast<chrono::microseconds>(end-start).count())+
			" us.\n";

	return res;
}

string sumOfArrayValues(int* polje, int N){
	string res;
	long long sum = 0;
	auto start = chrono::steady_clock::now();
	for(int i = 0; i < N; i++){
		sum += polje[i];
	}
	auto end = chrono::steady_clock::now();
	res = "Vsota vseh vrednosti polja: " + to_string(sum) + " \nSestevanje vrednosti indeksov polja (N elementov): " +
			to_string(chrono::duration_cast<chrono::microseconds>(end-start).count())+
			" us.\n";

	return res;
}





void speedTest(DLL* dll, int N){
	ofstream ofs("speedTest.txt", ofstream::trunc);
	string data;
	int* polje = new int[N];
	string res = "";
	res = inputAtListHead(dll, N);
	res += sumOfListValues(dll);
	res += inputAtFirstIofArray(polje, N);
	res += sumOfArrayValues(polje, N);
	res += inputAtEndOfArray(polje, N);

	delete polje;
	ofs << res;
};

bool menu(DLL* dll){
	cout << "Dvojno povezan seznam - izbira: " << endl << endl;
	cout << "1) Iskanje podatka" << endl;
	cout << "2) Vnos podatka v glavo" << endl;
	cout << "3) Vnos podatka za elementom" << endl;
	cout << "4) Vnos podatka za repom" << endl;
	cout << "5) Brisanje podatka" << endl;
	cout << "6) Izpis seznama od glave proti repu" << endl;
	cout << "7) Izpis seznama od repa proti glavi" << endl;
	cout << "8) Testiraj hitrost" << endl;
	cout << "9) Konec" << endl << endl;
	cout << "Izbira: ";

	switch(input()){
	case 1:
		cout << "Vnesi podatek za iskanje: ";
		dll->search(input());
		break;
	case 2:
		cout << "Vnesi podatek za vnos v glavo: ";
		dll->insertAtHead(input());
		break;
	case 3:
		int podatek, element;
		cout << "Vnos za elementom..\nPodatek: ";
		podatek = input();
		cout << "\nElement: ";
		element = input();
		dll->insertAfter(podatek, element);
		break;
	case 4:
		cout << "Vnesi podatek za vnos za repom: ";
		dll->insertAtTail(input());
		break;
	case 5:
		cout << "Vnesi podatek za izbris: ";
		dll->deleteNode(input());
		break;
	case 6:
		cout << "Seznam: ";
		dll->printList();
		break;
	case 7:
		cout << "Obrnjen seznam: ";
		dll->printReverse();
		break;
	case 8:
		cout << "Vnesite stevilo elementov za testiranje: ";
		speedTest(dll, input());
		break;
	case 9:
		dll->clearList();
		cout << "Program zakljucen."<< endl;
		return false;
	default:
		cout << "Napacen vnos, ponovi: ";
	}
	return true;
}

int main(){
	bool running = true;
	DLL* dll = new DLL();
	while(running){
		running = menu(dll);
	}

	delete dll;

}


