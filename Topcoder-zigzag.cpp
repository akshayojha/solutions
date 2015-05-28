/* 
   zigziag.cpp -- Topcoder Div 1
   Problem Statement: https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int size;
  int last, s_last;
  cin>> size;
  vector<int> l_num(size);
  for (int i = 0; i < size; ++i)
    cin>> l_num[i];
  // Remove duplicates
  for (int i = 1; i < size-1; ++i) {
    if (l_num[i] ==l_num[i+1]) {
      l_num.erase(l_num.begin()+i+1);
      i--;
      size--;
    }
  }
  // Given condition
  if (size <=2) {
    if (l_num[0] ==l_num[1]) {
      cout<< 1<< endl;
      return 0;
    }
    cout<< size<< endl;
    return 0;
  }

  vector<int> sol(size+1);
  // Base cases
  sol[0]=0;
  sol[1]=1;
  // Atleast 2 for all other cases
  for (int i = 2; i <= size; ++i)
    sol[i] =2;
  // Start dynamic programming
  for (int i = 3; i <= size; ++i) {
    int index =i-1;
    last =l_num[index-1];
    s_last =l_num[index-2];
    if ((last-s_last)*(l_num[index]-last) < 0) {
      sol[i] =max(sol[i-1]+1, sol[i]);
    } else {
    sol[i] =max(sol[i-1], sol[i]);
    }
  }
  cout<< sol[size]<< endl;
  return 0;
}
