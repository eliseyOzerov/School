// Example program
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    int k = 0;
    
    while(k<n){
        for(int i = k; i < n; i++){
            if(arr[i] < arr[k]){
                swap(&arr[i], &arr[k]);
            }
        }
        k++;
    }
    
    
}

int main(){
    
    
    
    int n = 1000;
    int arr[n];
    
    for(int i = 0; i<n; i++){
        arr[i] = rand() % 101 - 50;
    }

    cout << duration <<endl;
    for(int i = 0; i<n; i++){
      cout << arr[i] << endl;
    }
  
}
