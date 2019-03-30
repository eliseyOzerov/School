// Example program
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int insertionSort(int array[], int n){
    
    int j, key;
    
    for(int i = 0; i < n; i++){
        
        key = array[i];
        j = i;
        
        while(j > 0 && array[j-1] > key){
            array[j] = array[j-1];
            j--;
        }
        
        array[j] = key;
        
    }
    
}


int main()
{
  int arr[100];
  for(int i = 0; i < 100; i++){
    arr[i] = rand() % 101 - 50;
  }
  
  insertionSort(arr, 100);
  
  for(int i = 0; i < 100; i++){
      cout << arr[i] << endl ;
  }
  
  
}