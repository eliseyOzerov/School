#include <iostream>
using namespace std;

int main () {
    //Temperature dopoldne
    int dopoldne [5] = {6, 7, 10, 11, 2};
    //Temperature popoldne
    int popoldne [5] = {17, 18, 22, 14, 17};

    for (int i = 0; i < 5; i++) {

        if (dopoldne[i] < 12){
           cout << "#" << " ";
        } else {
            cout << dopoldne[i];
        }
        if (popoldne[i] > 35){
              cout << "?" << endl;
        } else {
            cout << popoldne[i] << endl;
        }

    }

    return 0;
}
