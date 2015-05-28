/* 
   angles.cpp -- HackerEarth Angles
   Problem Statement: https://www.hackerearth.com/problem/algorithm/angles-2/
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int knows, wants;
  // Take inputs
  cin >> knows >> wants;
  vector<int> raju(knows);
  vector<int> rani(wants);
  for (int i = 0; i < knows; ++i)
    cin >> raju[i];
  for (int i = 0; i < wants; ++i)
    cin >> rani[i];
  // Create vector to denote whether angle is possible
  vector<bool> sub(361);
  // Initally no angle is possible
  for (int i = 1; i <= 360; ++i)
    sub[i] =false;
  sub[0] =true;
  // Find all possible angles that can be drawn 
  for (int i = 0; i < knows; ++i) {
    for (int j = 1; j <= 360; ++j) {
      if (j >= raju[i] && sub[j-raju[i]]) sub[j] =true;
      int temp =raju[i];
      /* 
      Find all possible angles that can be formed
      by adding angles
      */
      for (int k = 2; (temp%360) > 0; ++k) {
        sub[(temp%360)] =true;
        temp =k*raju[i];
      }
    }
  }
  // Show result for all desired angles
  for (int i = 0; i < wants; ++i) {
    if (sub[rani[i]])
      cout<< "YES"<< endl;
    else
      cout<< "NO"<< endl;
  }
  return 0;
}
