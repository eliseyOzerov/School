#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;

void formatTable(string table[][6]){
	int cellWidth1 = 7;
	int cellWidth2 = 30;
	int size;
	string spaces = "";
	for(int k = 0; k < 166; k++){
		for(int i = 0; i < 6; i++){
			if(i == 1){
				size = cellWidth2-table[k][i].length();
				spaces = string(size, ' ');
				table[k][i] += spaces;
			} else {
				size = cellWidth1-table[k][i].length();
				spaces = string(size, ' ');
				table[k][i] += spaces;
			}
		}
	}
	
}

int sortTable(string array[][6], int n){
    
    int j, key;
    
    for(int i = 0; i < n; i++){
        
    	string arrCopy[6];

    	for(int l = 1; l < 6; l++){
    		arrCopy[l] = array[i][l];
    	}

        key = stoi(array[i][5]);
        j = i;
        
        while(j > 0 && stoi(array[j-1][5]) > key){
        	for(int k = 1; k < 6; k++){
        		array[j][k] = array[j-1][k];
        	}
            
            j--;
        }
        
        for(int l = 1; l < 6; l++){
    		array[j][l] = arrCopy[l];
    	}
        
    }
    
}


void fillTable(string table[][6], string names[], string surnames[]){
	int randomNameID, randomSurNameID;
	
	for(int i = 0; i < 166; i++){
		table[i][0] = to_string(i);
		randomNameID = rand() % 30;
		randomSurNameID = rand() % 20;
		table[i][1] = names[randomNameID] + "  " + surnames[randomSurNameID];
		table[i][2] = to_string((int)(rand() % 101));
		table[i][3] = to_string((int)(rand() % 101));
		table[i][4] = to_string((int)(rand() % 101));
		table[i][5] = to_string((int)(rand() % 10 +1));
	}

	formatTable(table);
}



void printTable(string table[][6], string names[], string surnames[]){
	int rv, vi, oc;
	double povprecje = 0;
	int k = 0;
	for(int i = 0; i < 166; i++){
		rv = stoi(table[i][3]);
		vi = stoi(table[i][4]);
		oc = stoi(table[i][5]);
		if(oc > 5){
			povprecje += oc * 1.0;
			k++;
		}
				
		for(int j = 0; j<5; j++){
			cout << table[i][j];
		}

		/*if(rv < 50 && vi < 50){
			cout << "RV,VI";
		} else if(vi < 50){
			cout << "VI";
		} else if (rv < 50){
			cout << "RV";
		} else {*/
			cout << table[i][5];
		//}

		
		cout << endl;
	}

	povprecje = povprecje / k;
	cout << povprecje << "  ";
	povprecje = round(povprecje * 100) / 100;
	cout << povprecje << endl;
	cout << "Studenti z najblizjo oceno: ";
	for(int i = 0; i < 166; i++){
		if(stoi(table[i][5]) == round(povprecje)){
			cout << table[i][0] << " ";
		}
	}
	cout << endl;
}

int main(){
	srand(time(NULL));
	string table[166][6];

	string names[30] = {"Laurence", "Claudio",  "Reynaldo",  "Bennett",  "Gaston",  "Spencer",  "Terence",
					"Perry",  "Pablo",  "Tomas",  "Hugo",  "Chris",  "Florentino",  "Hilario",  "Lanny",
					"Tana",  "Latarsha",  "Juliann", "Agnes",  "Marcene",  "Malika",  "Norah",  "Kiara",
					"Julieta",  "Edie",  "Jill",  "Yelena",  "Lorrine",  "Lucina",  "Deidre"};
	string surnames[20] = {"Hooper", "Spencer", "Torres", "Pennington", "Wiley", "Barber", "Oconnor",
						"Elliott", "Allen", "Mueller", "Hebert", "Howe", "Tucker", "Castaneda", "Gray", "Finley", "Rosario",
						"Ayers", "Holder", "Davis"};

	fillTable(table, names, surnames);
	sortTable(table, 166);
	printTable(table, names, surnames);


	return 0;
}

