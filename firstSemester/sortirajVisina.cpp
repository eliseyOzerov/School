#include <iostream>
#include <math.h>
using namespace std;

struct player{
	char ime[25];
	char priimek[25];
	unsigned int visina;
};

player p[200];

void sortiraj(player p[]){
	int k;
	player tmp;
	unsigned int visina;

	for(int i = 1; i<200; i++){

		k = i;
		visina = p[i].visina;
		tmp = p[i];

		while(k > 0 && visina >= p[k-1].visina){
			p[k] = p[k-1];
			k--;
		}
		p[k] = tmp;
	}
}


int main(){
	for(int i = 0; i < 200; i++){
		p[i].visina = rand() % 185;
	}
	for(int i = 0; i<200; i++){
		cout <<"Player n0: " << i << " " << p[i].visina << endl;
	}
	sortiraj(p);
	for(int i = 0; i<200; i++){
		cout << p[i].visina << endl;
	}
}