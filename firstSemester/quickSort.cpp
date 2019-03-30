#include <iostream>
#include <math.h>

using namespace std;

void quickSort(int arr[], int startID, int endID);
int partition(int arr[], int startID, int endID);
void swap(int * a, int * b);

int main(){

	int arr[] = {10, 2, -1, 33, 1, 5, 6, 23, 4, -11, 12};
	int n = 10;
    quickSort(arr, 0, n-1);
    
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }

}

void quickSort(int arr[], int startID, int endID){
    cout << "startID: " <<startID << " endID: " << endID <<endl;
    if(startID < endID){
        int pi = partition(arr, startID, endID);
        cout << "Pivot: " << arr[pi] << endl << endl;
        for(int i = startID; i<endID; i++){
            cout << arr[i] << " ";
        }
        cout << endl <<endl;
        quickSort(arr, startID, pi-1);
        quickSort(arr, pi+1, endID);
        
    }
    
}

int partition(int arr[], int startID, int endID){
    
    int pivot = arr[startID];
    int endOfLeftPart = startID+1;
    
    for(int currentElementID = startID+1; currentElementID <= endID; currentElementID++){
        if(arr[currentElementID] <= pivot){
            swap(&arr[currentElementID], &arr[endOfLeftPart]);
            endOfLeftPart++;
        }
    }
    swap(&arr[startID], &arr[endOfLeftPart-1]);
    return endOfLeftPart - 1;
}

void swap(int * a, int * b){
    int t = *a;
    *a = *b;
    *b = t;
}


