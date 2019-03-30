#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    cout << "Enter a num: " << endl;
    cin >> n;
    int numOfStars = 1;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n-i; k++){
            cout << "_";
        }
        
        for(int j = 0; j < numOfStars; j++){
            cout << "*";
        }
        numOfStars = numOfStars+2;
        cout <<endl;
    }
}