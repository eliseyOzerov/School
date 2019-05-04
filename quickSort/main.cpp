#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <math.h>
#include <time.h>
#include <chrono>

void swap(double* i, double* j){
    double tmp = *j;
    *j = *i;
    *i = tmp;
}

int deli(std::vector<double>& v, int dno, int vrh){
    int pivot = v[dno];
    int dn = dno;
    int vr = vrh;
    while(vr>dn){
        while(v[dn] <= pivot && dn < vrh){
            dn++;
        }
        while(v[vr] >= pivot && vr > dno){
            vr--;
        }
        if(vr > dn){
            swap(&v[dn], &v[vr]);
        }
    }
    swap(&v[dno], &v[vr]);
    return vr;
}

void quickSort(std::vector<double>& v, int dno, int vrh){
    if(dno < vrh){
        int j = deli(v, dno, vrh);
        quickSort(v, dno, j-1);
        quickSort(v, j+1, vrh);
    }
}
void insertionSort(std::vector<double>& v)
{
    int i, key, j;
    int n = v.size();
    for (i = 1; i < n; i++) {
        key = v[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}


void quickSortMedian(std::vector<double>& v, int dno, int vrh){
    if(dno < vrh){
        int m = dno + (vrh-dno)/ 2;
        swap(&v[dno], &v[m]);
        int j = deli(v, dno, vrh);
        quickSortMedian(v, dno, j-1);
        quickSortMedian(v, j+1, vrh);
    }
}
void generateRandomSequence(std::vector<double>& v, int k){
    for(int i = 0; i < k; i++){
        v.push_back(rand());
    }
}

void generateIncreasingSequence(std::vector<double>& v, int k){
    for(int i = 0; i < k; i++){
        v.push_back(i);
    }
}

void generateDecreasingSequence(std::vector<double>& v, int k){
    for(int i = k; i > 0; i--){
        v.push_back(i);
    }
}

bool sorted(std::vector<double> v){
    if(v.front() <= v.back()){
        if(v.size()>1){
            for(int i = 1; i < v.size()-1; i++){
                if(v[i]<=v[i-1]){
                    return false;
                }
            }
        }
        return true;
    }
}

bool menu(std::vector<double> &v){
    int izbira, velikost;

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff;
    std::cout << "Hitro uredi - izbira: " << std::endl << std::endl;
    std::cout << "1) Generiraj nakljucno zaporedje" << std::endl;
    std::cout << "2) Generiraj narascajoce zaporedje" << std::endl;
    std::cout << "3) Generiraj padajoce zaporedje" << std::endl;
    std::cout << "4) Izpis zaporedja" << std::endl;
    std::cout << "5) Preveri ali je zaporedje urejeno" << std::endl;
    std::cout << "6) Uredi s hitrim urejanjem brez mediane" << std::endl;
    std::cout << "7) Uredi s hitrim urejanjem z mediano" << std::endl;
    std::cout << "8) Uredi z drugim algoritmom za urejanje" << std::endl;
    std::cout << "9) Konec" << std::endl << std::endl;
    std::cout << "Izbira: " << std::endl;
    while(!(std::cin>>izbira)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Your input is invalid, try again: ";
    }
    switch(izbira){
        case 1:
            std::cout << "Vnesi velikost polja: " ;
            while(!(std::cin>>velikost)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Your input is invalid, try again: ";
            }
            while(velikost < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Your input is invalid, try again: ";
            }
            v.clear();
            generateRandomSequence(v, velikost);
            break;
        case 2:
            std::cout << "Vnesi velikost polja: " ;
            while(!(std::cin>>velikost)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Your input is invalid, try again: ";
            }
            while(velikost < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Your input is invalid, try again: ";
            }
            v.clear();
            generateIncreasingSequence(v, velikost);
            break;
        case 3:
            std::cout << "Vnesi velikost polja: " ;
            while(!(std::cin>>velikost)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Your input is invalid, try again: ";
            }
            while(velikost < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Your input is invalid, try again: ";
            }
            v.clear();
            generateDecreasingSequence(v, velikost);
            break;
        case 4:
            if(v.size()<1){
                std::cout << "Vector empty.\n";
                break;
            }
            std::cout << "Zaporedje: ";
            for(double i : v){
                std::cout << i << ' ';
            }
            std::cout << std::endl;
            break;
        case 5:
            if(v.size()<1){
                std::cout << "Array empty.\n";
                break;
            }
            if(sorted(v)){
                std::cout << "Array is sorted." << std::endl;
            } else {
                std::cout << "Array isn't sorted." << std::endl;
            }
            break;
        case 6:
            if(v.size()<1){
                std::cout << "Array empty.\n";
                break;
            }
            std::cout << "Sorting..." << std::endl;
            start = std::chrono::system_clock::now();
            quickSort(v, 0, v.size()-1);
            end = std::chrono::system_clock::now();;
            diff = end - start;
            std::cout << "Sorted. Time needed: " << diff.count() << "s\n";
            break;
        case 7:
            if(v.size()<1){
                std::cout << "Array empty.\n";
                break;
            }
            std::cout << "Sorting with median..." << std::endl;
            start = std::chrono::system_clock::now();
            quickSortMedian(v, 0, v.size()-1);
            end = std::chrono::system_clock::now();;
            diff = end - start;
            std::cout << "Sorted. Time needed: " << diff.count() << "s\n";
            break;
        case 8:
            if(v.size()<1){
                std::cout << "Array empty.\n";
                break;
            }
            std::cout << "Insertion sorting..." << std::endl;
            start = std::chrono::system_clock::now();
            insertionSort(v);
            end = std::chrono::system_clock::now();;
            diff = end - start;
            std::cout << "Sorted. Time needed: " << diff.count() << "s\n";
            break;
        case 9:
            std::cout << "Exiting... " << std::endl;
            return false;
        default:
            std::cout << "Wrong value, try again.\n";
            break;
    }
    return true;
}

int main() {
    std::vector<double> v;
    std::srand(time(nullptr));
    bool b = true;
    while(b){
        b = menu(v);
    }

    return 0;
}