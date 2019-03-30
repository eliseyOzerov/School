// Example program
#include <iostream>
#include <string>
using namespace std;

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    bool sorted = false;
    
    while(!sorted){
        sorted = true;
        for(int i = 0; i < n; i++){
            if(arr[i] > arr[i+1]){
                sorted = false;
                swap(&arr[i], &arr[i+1]);
            }
        }
    }
    
}

int main()
{
  int arr[] = {1, -2, 4, 11, 56, -20, 5, 7,3, 4};
  int n = 10;
  bubbleSort(arr, n);
  for(int i = 0; i<n; i++){
      cout << arr[i] << " ";
  }
  
}