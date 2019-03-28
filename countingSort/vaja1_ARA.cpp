/*
 * countingSort.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: ultron
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



int convertArray(int *array, int size){

	int min = 0;

	for(int i = 0; i < size; i++){
		if(array[i]<min){
			min = array[i];
		}
	}
	if(min<0){
		for(int i = 0; i < size; i++){
			array[i]-=min;
		}
	}

	return min;
}

int getMaxVal(int array[], int size){
	int max = array[0];

	for(int i = 0; i < size; i++){
		if(array[i]>max){
			max = array[i];
		}
	}

	return max;
}
int * countingSort(int *array, int size, int maxVal){
	int * arrayCopyC = new int[maxVal+1];
	int * res = new int[size];

	for(int i = 0; i < size; i++){
		arrayCopyC[array[i]]+=1;
	}

	for(int i = 1; i < maxVal+1; i++){
		arrayCopyC[i]+=arrayCopyC[i-1];
	}

	for(int i = size-1; i >= 0; i--){
		res[arrayCopyC[array[i]]-1]=array[i];
		arrayCopyC[array[i]]--;
	}
	delete arrayCopyC;
	return &res[0];

}

int * romanSort(int * array, int size, int maxVal){
	int * arrayCopyC = new int[maxVal+1];
	int resIndex = 0;
	int * res = new int[size];

	for(int i = 0; i < size; i++){
		arrayCopyC[array[i]]+=1;
	}

	for(int i = 0; i<maxVal+1; i++){

		for(int k = resIndex; k<resIndex+arrayCopyC[i]; k++){
			res[k]=i;
		}

		resIndex += arrayCopyC[i];
	}
	delete arrayCopyC;
	return &res[0];
}



bool Branje_Stevil(vector<int> &vec, const char s[]) {
	ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		vec.push_back(st);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost, int min) {
	ofstream output("out.txt");

	for (int i = 0; i<velikost; i++){
		if(min < 0){
			polje[i]+=min;
		}

		output << polje[i] << ' ';
	}

}

int main(int argc, const char* argv[]) {
	vector<int> A;


	int * res;

	if (argc < 3) return 0;
	if (!Branje_Stevil(A, argv[2])) return 0;

	int arr_size = A.size();
	int min = convertArray(&A[0], arr_size);

	if (argv[1][0] == '0') {
		res = countingSort(&A[0], arr_size, getMaxVal(&A[0], arr_size));
	}
	else {
		res = romanSort(&A[0], arr_size, getMaxVal(&A[0], arr_size));
	}
	Izpis_Stevil(res,A.size(), min);

	return 0;
}




