#include <iostream>
#include <vector>
using namespace std;

/* Pogledamo, če je poteza na voljo*/
bool checkIfMoveAvailable(int x, int y, vector< vector<int> > board){
	int N = board[0].size();
	return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0;
}

/*Rekurzivna funkcija
*/
bool tour(int x, int y, int possibleMoves[8][2], int moves, vector< vector<int> > board){
	/*Izpis trenutnega stanja matrike*/
	string res = ""; //niz za matriko
	int N = board[0].size();
	for(int i = N-1; i >= 0; i--){
		for(int j = 0; j < N; j++){
			res = res + to_string(board[j][i]) + string(3 - to_string(board[j][i]).length(), ' ');
		}
		res = res +"\n";
	}
	res = res +"\n";
	cout << res;

	//če je števec korakov enak velikosti sahovnice, vrnemo true
	if(moves == N*N){
		return true;
	}

	//glavna zanka funkcije - ponavljamo 8 krat, ker imamo največ 8 korakov, ki jih lahko izvede skakac
	for(int i = 0; i < 8; i++){
		//pogledamo, ce je določen korak na voljo (ni izven sahovnice in ne stopimo tja, kjer smo ze bili)
		if(checkIfMoveAvailable(x + possibleMoves[i][0], y + possibleMoves[i][1], board)){
			//na naslednje mesto zapišemo število skokov + 1
			board[x + possibleMoves[i][0]][y + possibleMoves[i][1]] = moves+1;
			//rekurzivno pogledamo, če je izbrana pot veljavna rešitev
			if(tour(x + possibleMoves[i][0], y + possibleMoves[i][1], possibleMoves, moves+1, board)){
				return true;
			//ce ni, vrnemo vrednost mesta, kamor smo skočili nazaj na 0
			} else {
				board[x + possibleMoves[i][0]][y + possibleMoves[i][1]] = 0;
			}
		}
	}
	//če ne najdemo nobene zadovoljive poti, vrnemo false
	return false;
}



int main(){
	int N;
	int zacX, zacY;

	cout << "Vnesite velikost sahovnice: ";
	cin >> N;

	cout << "Vnesite zacetno koordinato X: ";
	cin >> zacX;
	cout << "Vnesite zacetno koordinato Y: ";
	cin >> zacY;

	vector<vector<int>> board(N, vector<int>(N));
	board[zacX][zacY] = 1;

	int possibleMoves[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2,-1},   
						{-2, 1}, {-1, 2}};

	if(!tour(0, 0, possibleMoves, 1, board)){
		cout << "Tour doesn't exist." << endl;
	}

}