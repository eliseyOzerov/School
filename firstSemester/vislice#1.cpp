#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <exception>
#include <iomanip>
#include <time.h>
using namespace std;

/*Struktura igralca*/

struct player{
	string ime;
	string vpisna;
	string trGeslo;
	double cas;
	int nPoskusi; /*namesto števila vseh poskusov ugibanj, uporabljam napačne poskuse,
	saj pri različnih besedah bo število vseh poskusov tudi pri zmagi različno, tako pa gledamo, kdo naredi najmanj napak*/
};

player& ustvariIgralca(vector<player>& pv){

	cout << "Novi igralec....." << endl;
	string ime, vpisna;
	int nPoskusi;

	cout << "Vnesite ime igralca: ";
	cin >> ime;

	cout << "Vnesite vpisno številko igralca: ";
	cin >>  vpisna;

	player p{ime, "", "", 0, nPoskusi};

	pv.push_back(p);

	return pv.back();
}

/*Izbiramo igralca*/

player& izberiIgralca(vector<player>& pv){
	cout << "Izbira igralca....." << endl;
	string ime;
	while(true){
		cout << "Vnesite ime igralca: ";
		cin >> ime;
		for(int i = 0; i < pv.size(); i++){
			if(pv[i].ime == ime){
				return pv[i];
			}
		}
		cout << "Igralec ne obstaja.";
	}
	
}

/*Sekljamo spodaj naveden string po besedam, da dobimo besede za naključno izbiro v igri*/

void split(string s, vector<string> & v){
	bool znak = false;
	string temp = "";
	char znaki[] = {' ', '.', ',', '-', ':', '!'}; //znaki, po katerim ločimo besede
	for(int i = 0; i < s.length(); i++){//za celi string preglej
		znak = false; //predpostavljamo, da ni false
		for(int j = 0; j < 6; j++){ //za vsak znak preglej
			if(s[i] == znaki[j]){
				znak = true;
				break;
			}
		}
		if(!znak){ // ce ni locilo, dodamo znak v temp string
			temp+=s[i];
		} else {
			v.push_back(temp); // ce je locilo, prenesemo temp string v vektor in sprazimo celico
			temp = "";
		}
	}

}

//pretvorba v lowercase

string toLowercase(string s){
	for(int i = 0; i<s.length(); i++){
		if(int(s[i]) >= 65 && int(s[i]) <= 90){
			char c = char(int(s[i])+32);
			s.replace(i, 1, "c");
		}
	}
	return s;
}

//formatiramo vektor
/*izbrisemo vse besede manjše od 4, jih pretvorimo v lowercase in pustimo samo 100 besed*/;

void formatVector(vector<string> &v){
	for(int i = 0; i<v.size(); i++){
		while(v.at(i).length() < 4){
			v.erase(v.begin()+i);
		}
		v.at(i) = toLowercase(v.at(i));
	}
	while(v.size()>100){
		v.pop_back();
	}
}

//glavni program za ugibanje

void ugibanjeGesla(player &p, string *str[]){
	char c;
	bool uganjeno = false;
	int napacniPoskusi = 0;
	int beginning = 0;
	string s = p.trGeslo;
	chrono::duration<double> diff;
	vector<char> beseda(s.length(), '_');


	

	auto startTime = chrono::system_clock::now();

	while(!uganjeno){ // dokler nismo uganili
		cout << "Vnesite crko: ";
		cin >> c;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoriramo vse za prvim charom
		if(s.find(c) != string::npos){ //if c in s
			cout << "Uganili ste crko: ";
			beginning = s.find(c); //start the next search from this point
			while(s.find(c, beginning) != string::npos){
				beseda.at(s.find(c, beginning)) = c; //insert char to all occurencies
				if(beginning < s.length()-1){ //find the next one
					beginning = s.find(c, beginning+1);
				} else {
					break;
				}
				
			}
			uganjeno = true;
			//if we find at least one empty space in beseda, we're not done yet
			for(int i = 0; i < s.length(); i++){
				if(beseda[i] == '_'){
					uganjeno = false;
				}
				cout << beseda[i];
			}
			cout << endl;
		} else {
			//if we didn't guess the char, we update nPoskusi of the player
			p.nPoskusi = napacniPoskusi;
			if(napacniPoskusi < 9){
				cout << "Niste uganili. Trenutno stanje: " << endl;
				cout << *str[napacniPoskusi++];
			} else {
				auto endTime = chrono::system_clock::now();
				diff = endTime - startTime;
				cout << *str[napacniPoskusi];
				p.cas = diff.count();
				cout << "Izgubili ste. Porabljen čas: " << p.cas << endl<<endl;
				return;
			}
			

		}

	}
	

	auto endTime = chrono::system_clock::now();

	diff = endTime - startTime;
	p.cas = diff.count();

	cout << "Uganili ste besedo! Porabili ste " << p.cas << " sekund in " << p.nPoskusi << " napacnih poskusov." << endl;
}

void insertionSort(vector<player> &pv){
    int j, key;
    player p;
    
    for(int i = 0; i < pv.size(); i++){
        
        p = pv[i];
        key = pv[i].nPoskusi;
        j = i;
        
        while(j > 0 && pv[j-1].nPoskusi > key){
            pv[j] = pv[j-1];
            j--;
        }

        pv[j] = p;
        
    }
    
}

void izpisStatistike(vector<player>& pv){

	cout <<
	"<html>\n"
	"<head>\n"
	"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n"
	"<title>Naloga N6: Vislice</title>\n"
	"</head>" << endl;

	if(pv.size() > 0){
		for(int i = 0; i < pv.size(); i++){
			cout <<
			"<div>\n"
			"<span style=\"width:200px;display:table-cell;\">" << pv[i].ime << "</span>\n"
			"<span style=\"width:200px;display:table-cell;\">\"" << pv[i].trGeslo << "\"</span>\n"
			"<span style=\"width:100px;display:table-cell;\">" << pv[i].nPoskusi+1 << "</span>\n"
			"<span style=\"width:50px;display:table-cell;\">" << pv[i].cas << "</span>\n"
			"</div>" << endl;
			
		}

		cout << "</html>" << endl;
	} else {
		cout << "Igralci ne obstajajo." << endl;
	}
}


int main(){

	string tekst = "Apartments simplicity or understood do it we. Song such eyes had and off. Removed winding ask explain delight out few behaved lasting. Letters old hastily ham sending not sex chamber because present. Oh is indeed twenty entire figure. Occasional diminution announcing new now literature terminated. Really regard excuse off ten pulled. Lady am room head so lady four or eyes an. He do of consulted sometimes concluded mr. An household behaviour if pretended. "

"Name were we at hope. Remainder household direction zealously the unwilling bed sex. Lose and gay ham sake met that. Stood her place one ten spoke yet. Head case knew ever set why over. Marianne returned of peculiar replying in moderate. Roused get enable garret estate old county. Entreaties you devonshire law dissimilar terminated. "

"Improve him believe opinion offered met and end cheered forbade. Friendly as stronger speedily by recurred. Son interest wandered sir addition end say. Manners beloved affixed picture men ask. Explain few led parties attacks picture company. On sure fine kept walk am in it. Resolved to in believed desirous unpacked weddings together. Nor off for enjoyed cousins herself. Little our played lively she adieus far sussex. Do theirs others merely at temper it nearer. "

"In to am attended desirous raptures declared diverted confined at. Collected instantly remaining up certainly to necessary as. Over walk dull into son boy door went new. At or happiness commanded daughters as. Is handsome an declared at received in extended vicinity subjects. Into miss on he over been late pain an. Only week bore boy what fat case left use. Match round scale now sex style far times. Your me past an much."

"Oh acceptance apartments up sympathize astonished delightful. Waiting him new lasting towards. Continuing melancholy especially so to. Me unpleasing impossible in attachment announcing so astonished. What ask leaf may nor upon door. Tended remain my do stairs. Oh smiling amiable am so visited cordial in offices hearted.";

	string stanje1 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje2 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*          *                    *\n"
	"*         *                     *\n"
	"*        *                      *\n"
	"*       *                       *\n"
	"*      *                        *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje3 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*                               *\n"
	"*          *                    *\n"
	"*         * *                   *\n"
	"*        *   *                  *\n"
	"*       *     *                 *\n"
	"*      *       *                *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje4 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*         * *                   *\n"
	"*        *   *                  *\n"
	"*       *     *                 *\n"
	"*      *       *                *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje5 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*          *************        *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*         * *                   *\n"
	"*        *   *                  *\n"
	"*       *     *                 *\n"
	"*      *       *                *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje6 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*          *************        *\n"
	"*          *    *      *        *\n"
	"*          *  *        *        *\n"
	"*          **          *        *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*         * *                   *\n"
	"*        *   *                  *\n"
	"*       *     *                 *\n"
	"*      *       *                *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje7 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*          *************        *\n"
	"*          *    *      *        *\n"
	"*          *  *        *        *\n"
	"*          **          *        *\n"
	"*          *          ---       *\n"
	"*          *          ---       *\n"
	"*          *                    *\n"
	"*          *                    *\n"
	"*         * *                   *\n"
	"*        *   *                  *\n"
	"*       *     *                 *\n"
	"*      *       *                *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje8 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*          *************        *\n"
	"*          *    *      *        *\n"
	"*          *  *        *        *\n"
	"*          **          *        *\n"
	"*          *          ---       *\n"
	"*          *          ---       *\n"
	"*          *           |        *\n"
	"*          *           |        *\n"
	"*         * *                   *\n"
	"*        *   *                  *\n"
	"*       *     *                 *\n"
	"*      *       *                *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje9 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*          *************        *\n"
	"*          *    *      *        *\n"
	"*          *  *        *        *\n"
	"*          **          *        *\n"
	"*          *          ---       *\n"
	"*          *          ---       *\n"
	"*          *          /|\\       *\n"
	"*          *         / | \\      *\n"
	"*         * *                   *\n"
	"*        *   *                  *\n"
	"*       *     *                 *\n"
	"*      *       *                *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";

	string stanje10 = 
	"*********************************\n"
	"*                               *\n"
	"*                               *\n"
	"*          *************        *\n"
	"*          *    *      *        *\n"
	"*          *  *        *        *\n"
	"*          **          *        *\n"
	"*          *          ---       *\n"
	"*          *          ---       *\n"
	"*          *          /|\\       *\n"
	"*          *         / | \\      *\n"
	"*         * *         / \\       *\n"
	"*        *   *       /   \\      *\n"
	"*       *     *                 *\n"
	"*      *       *                *\n"
	"*     ***********               *\n"
	"*                               *\n"
	"*********************************\n";
	vector<string> v;
	split(tekst, v);
	formatVector(v);
	
	string * str[10] = {&stanje1, &stanje2, &stanje3, &stanje4, &stanje5, 
		&stanje6, &stanje7, &stanje8, &stanje9, &stanje10};

	vector<player> p;

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

		player * player;

		switch(n){
			case 1: player = &ustvariIgralca(p);
					break;
			case 2: player = &izberiIgralca(p);
					break;
			case 3: izpisStatistike(p);
					continue;
			case 4: return 0;
		}

		(*player).trGeslo = v[rand() % 100];
		ugibanjeGesla(*player, str);
		insertionSort(p);
		
		
	}
	

}