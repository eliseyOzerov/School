// Example program
#include <iostream>
#include <string>

using namespace std;

double length;
double duration;
double speed;
double rest;

string beyond = "Cyclist is beyond the finish line.";
string notyet = "Cyclist still struggles to reach his destination.";

int main()
{
  cout << "Please enter trip length[km], duration[h] and speed[km/h] separately: " << endl;
  cin >> length;
  cin >> duration;
  cin >> speed;

  cout << "length = "  << length << ' ' << "duration = " << duration << ' ' << "speed = " << speed << endl;

  rest = length - duration * speed;

  if (rest > 0){
      cout << notyet;
  } else {
      cout << beyond;
  }

  return 0;
}

