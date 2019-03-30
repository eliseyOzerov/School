#include <iostream>
#include <math.h>
using namespace std;

bool prastevilo(int n);
int sestejPrast();
int povpPolja(int P[],int j);

int main()
{
    int n;
    const int j = 1;
    int P[20];

    cout << "Vnesi naravno stevilo: ";
    cin >> n;
    cout <<"Funkcija 1"<< endl;
    bool jePrastevilo = prastevilo(n);
    if(jePrastevilo){
        cout << n << " je prastevilo." << endl;
    } else {
        cout << n << " ni prastevilo." << endl;
    }
    cout << "Funkcija 2" <<endl;
    cout << "Med -217 in 9001 je " << sestejPrast() << " prastevil." << endl;
    cout << "Funkcija 3" << endl;
    cout << "Povprecna vrenost prvih 20 prastevil, ki so vecja ali enaka od " << j << " je enaka " << povpPolja(P, j) << "." <<endl;
    
    int novoSt;
    
    cout << "Vnesite novo stevilo: ";
    cin >> novoSt;
    
    double novoStKor = sqrt(novoSt);
    double razdalja = 20;
    double razTemp;
    int rezPrast;
    
    cout << "Koren tega st. je: " << novoStKor <<endl;
    
    for(int i = 19; i > -1; i--){
        if(P[i] < novoStKor){
            rezPrast = P[i];
            break;
        } else if(i<1){
            rezPrast = P[0];
        }
    }
    
    cout << "Najblizje prastevilo iz polja je: " << rezPrast << endl;
    
    return 0;
}

bool prastevilo(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}


int sestejPrast(){
    int k = 0;
    for(int i = -217; i <= 9001; i++){
        if(prastevilo(i)){
            k++;
        }
    }
    return k;
}

int povpPolja(int P[20], int n){
    int i = 0;
    int povp = 0;

    while(i < 20){
        if(prastevilo(n)){
            P[i] = n;
            povp+=n;
            i++;
        }
        n++;
    }

    for(int i = 0; i<20; i++){
        cout << P[i] << " ";
    } 
    cout << endl;
    int rez = povp/20;
    return rez;
}