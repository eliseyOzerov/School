#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <exception>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;

struct player{
	string ime;
	string vpisna;
	string trGeslo;
	int nPoskusi;
	double cas;
	vector<char> ugCrke;
	player * next;
	player(string ime, player *next){
		this->ime = ime;
		this->next = next;
	}
};

player* ustvariIgralca(player * &first){

	int max = 0;
	int stIgralcev = 0;
	int nPoskusi;

	cout << "Novi igralec....." << endl;
	string ime, vpisna;

	cout << "Vnesite ime igralca: ";
	cin >> ime;

	cout << "Vnesite vpisno številko igralca: ";
	cin >>  vpisna;

	//ustvarimo novega igralca
	player * p = new player(ime, first);
	//change head to created player
	first = p;

	player * worst, *temp, *prev;
	temp = first; // put head player in temp (copy him)

	while(temp != NULL){ //dokler temp ni NULL, najdi najslabšega igralca
		stIgralcev++;
		if(temp->next && temp->next->nPoskusi >= max){ //poglej, ce imamo naslednji element v listu, in če je nPoskusi >= max poskusi
			
			max = temp->next->nPoskusi;
			worst = temp->next;
			prev = temp;
		}
		temp = temp->next;
	}

	if(stIgralcev > 5){
		prev->next = worst->next;
		delete worst;
	}
	
	return p;
}

player* izberiIgralca(player * &temp){
	cout << "Izbira igralca....." << endl;
	string ime;
	while(true){
		cout << "Vnesite ime igralca: ";
		cin >> ime;
		while(temp != NULL){
			if(temp->ime == ime){
				return temp;
			}
		}
		cout << "Igralec ne obstaja." << endl;
	}
	
}



void split(string s, vector<string> & v){
	bool znak = false;
	string temp = "";
	char znaki[] = {' ', '.', ',', '-', ':', '!'};
	for(int i = 0; i < s.length(); i++){
		znak = false;
		for(int j = 0; j < 6; j++){
			if(s[i] == znaki[j]){
				znak = true;
				break;
			}
		}
		if(!znak){
			temp+=s[i];
		} else {
			v.push_back(temp);
			temp = "";
		}
	}

}

string toLowercase(string s){
	for(int i = 0; i<s.length(); i++){
		if(int(s[i]) >= 65 && int(s[i]) <= 90){
			char c = char(int(s[i])+32);
			s.replace(i, 1, 1, c);
		}
	}
	return s;
}

void formatVector(vector<string> &v){
	for(int i = 0; i<v.size(); i++){
		while(v.at(i).length() < 4){
			v.erase(v.begin() + i);
		}
		v.at(i) = toLowercase(v.at(i));
	}
	while(v.size()>100){
		v.pop_back();
	}
}	

void ugibanjeGesla(player &p, string str[]){
	char c;
	bool uganjeno = false;
	int napacniPoskusi = 0;
	int beginning = 0;
	string s = p.trGeslo;
	chrono::duration<double> diff;
	vector<char> beseda(s.length(), '_');


	

	auto startTime = chrono::system_clock::now();

	while(!uganjeno){
		cout << "Vnesite crko: ";
		cin >> c;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if(s.find(c) != string::npos){
			cout << "Uganili ste crko: ";
			beginning = s.find(c);
			while(s.find(c, beginning) != string::npos){
				beseda.at(s.find(c, beginning)) = c;
				if(beginning < s.length()-1){
					beginning = s.find(c, beginning+1);
				} else {
					break;
				}
				
			}
			uganjeno = true;
			for(int i = 0; i < s.length(); i++){
				if(beseda[i] == '_'){
					uganjeno = false;
				}
				cout << beseda[i];
			}
			cout << endl;
		} else {
			p.nPoskusi = napacniPoskusi;
			if(napacniPoskusi < 9){
				cout << "Niste uganili. Trenutno stanje: " << endl;
				cout << str[napacniPoskusi++];
			} else {
				auto endTime = chrono::system_clock::now();
				diff = endTime - startTime;
				cout << str[napacniPoskusi];
				p.cas = diff.count();
				cout << "Niste uganili. Porabljen čas: " << p.cas << endl<<endl;
				return;
			}
			

		}

	}
	

	auto endTime = chrono::system_clock::now();

	diff = endTime - startTime;
	p.cas = diff.count();

	cout << "Uganili ste! Porabljen čas: " << p.cas << " sekund." << endl;
}

/*void insertionSort(player * &temp){
    int j, key;
    player p;
    
    for(int i = 0; i < pv.size(); i++){
        
        p = pv[i];
        key = pv[i].ugCrke.size();
        j = i;
        
        while(j > 0 && pv[j-1].ugCrke.size() > key){
            pv[j] = pv[j-1];
            j--;
        }

        pv[j] = p;
        
    }
    
}*/

void izpisStatistike(player * temp){
	player * pl = temp;
	while(pl){
		cout << endl << "Ime: " << pl->ime << " nPoskusi: " << pl->nPoskusi << " Geslo: " << pl->trGeslo << endl << endl;
		pl = pl->next;
	}

	ofstream file("statistika.txt");

	file <<
	"<html>\n"
	"<head>\n"
	"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n"
	"<title>Naloga N6: Vislice</title>\n"
	"</head>" << endl;

	if(temp != NULL){
		while(temp != NULL){
			file <<
			"<div>\n"
			"<span style=\"width:200px;display:table-cell;\">" << temp->ime << "</span>\n"
			"<span style=\"width:200px;display:table-cell;\">\"" << temp->trGeslo << "\"</span>\n"
			"<span style=\"width:100px;display:table-cell;\">" << temp->nPoskusi+1 << "</span>\n"
			"<span style=\"width:50px;display:table-cell;\">" << temp->cas << "</span>\n"
			"</div>" << endl;
			temp = temp->next;
		}

		file << "</html>" << endl;
	} else {
		cout << "Igralci ne obstajajo." << endl;
	}
}


int main(){


	
	ifstream ifs("vislice_tekst.txt");
	stringstream ss;
	ss << ifs.rdbuf();
	string tekst;
	tekst = ss.str();

	string besedilo = "";
	string stanja = "";

	int i = 0;

	while(tekst.at(i) != '\n'){
		besedilo += tekst.at(i);
		i++;
	}

	while(i < tekst.length()){
		stanja += tekst.at(i);
		i++;
	}

	vector<string> v;
	split(besedilo, v);
	formatVector(v);
	
	string stanja_arr[10];
	int k = 0;
	string temp;
	for(int i = 0; i < 10; i++){
		temp = "";
		while(k < stanja.length()){
			if(stanja.at(k) == ';' && temp != ""){
				stanja_arr[i] = temp + "\n";
				k+=2;
				break;
			}
			temp += stanja.at(k);
			k++;
		}
	}

	
	player * first = NULL;

	while(true){
		srand(time(NULL));

		int n;

		cout << "Ustvari novega igralca: 1\nIzberi obstoječega igralca: 2\n"
		"Izpis statistike: 3\nIzhod: 4\n";
			
		while(!(cin >> n) || !(n >= 1 && n <= 4)){

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Vnesite pravilen znak! ";
		}

		player* player;
		int stIgralcev = 0;

		switch(n){
			case 1: player = ustvariIgralca(first);
					break;
			case 2: player = izberiIgralca(first);
					break;
			case 3: izpisStatistike(first);
					continue;
			case 4: return 0;
		}

		int maxDolzina = 0;
		for(int i = 0; i<v.size(); i++){
			if(v.at(i).length() > maxDolzina){
				maxDolzina = v.at(i).length();
			}
		}

		int dolzinaBesede;
		cout << "Vnesite dolzino besede od 4 do " << maxDolzina << ": ";
		cin >> dolzinaBesede;
		std::vector<string> besede;

		for(int i = 0; i<v.size(); i++){
			if(v.at(i).length() == dolzinaBesede){
				besede.push_back(v.at(i));
			}
		}

		(*player).trGeslo = besede[rand() % besede.size()];
		ugibanjeGesla(*player, stanja_arr);
		
		
	}

}