#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int k = 10;
    bool star = false;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(star){
                cout << "*";
            } else {
                cout << "_";
            }
            star = !star;
        }
        cout << endl;
        star = !star;
    }
}