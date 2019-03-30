// Example program
#include <iostream>
#include <string>

using namespace std;


void izrisiGraf(int i, int x, int tekm, int id);

int main()
{
    double length;
    double duration;
    double speed;
    double rest; //ostanek poti
    double donePercent; //prevozeni procent proge
    int N; //stevilo vrstic
    double speedArr[5] = {0, 20, 30, 40, 50};//hitrosti tekmovalcev

    string beyond = "Cyclist is beyond the finish line.";
    string notyet = "Cyclist 1 still struggles to reach his destination.";

  cout << "Please enter trip length[km], duration[h] and speed[km/h] separately: " << endl;
  cin >> length;
  cin >> duration;
  cin >> speed;

  speedArr[0] = speed;

  cout << "Please enter number of rows for progress graph: " << endl;
  cin >> N;

  cout << "length = "  << length << ' ' << "duration = " << duration << ' ' << "speed = " << speed << endl;

  rest = length - duration * speed;


  if (rest > 0){
      cout << notyet << endl;
  } else {
      cout << beyond << endl;
  }

  for (int i = 0; i < sizeof(speedArr)/sizeof(speedArr[0]); i++){
      donePercent = (int)(duration * speedArr[i] * 100 / length);
      izrisiGraf(donePercent, N, 1, i);
  }


  return 0;
}

void izrisiGraf(int donePercent, int N, int tekm, int id){
    cout << "Tekmovalec " << id + 1 << "(" << donePercent << "%)" << endl;
    for (int i = 0; i < N; i++){
        for (int i = 0; i < donePercent; i++){
            cout << "*";
        }
        for (int i = 0; i < 100-donePercent; i++){
            cout << ".";
        }
        cout << endl;
    }
}

