/* 
   kilmanx.cpp 
   Problem Statement: http://community.topcoder.com/stat?c=problem_statement&pm=2288&rd=4725
*/

#include <iostream>
#include <queue>

using namespace std;
// Array denoting visited states of the game
bool visited[32768];
// Class denoting nodes in graph
class node {
 public:
  int weap;
  int cost;
};
/*
  Overload '<' operator to get minimum element on
  top of priority queue
*/
bool operator<(const node& a, const node& b) {
    if (a.cost != b.cost) return (a.cost > b.cost);
    if (a.weap != b.weap) return (a.weap > b.weap);
    return false;
}

int main(int argc, char *argv[]) {
  // Take inputs
  int n_boss;
  cin>> n_boss;
  int health[n_boss];
  string damage[n_boss];
  for (int i = 0; i < n_boss; ++i)
    cin >> health[i];
  for (int i = 0; i < n_boss; ++i)
      cin >> damage[i];
  // Initially no state has been visited    
  for (int i = 0; i < 32768; ++i)
    visited[i] =false;
  // Priority queue to implement Dijkstra  
  priority_queue<node> pq;
  // Create initial node object with no weapon and cost
  node start;
  start.weap =0;
  start.cost =0;
  // Push initial node to queue
  pq.push(start);
  // Start Dijkstra's Algorithm
  while (pq.empty() ==false) {
  /* 
  Take out the first node from the queue
  which will have the minimum shots required to kill
  a boss
  */
    node tmp =pq.top();
    pq.pop();
    if (visited[tmp.weap]) continue;
    visited[tmp.weap] =true;
    /* 
    Check whether goal has been reached i.e all bosses
    have been killed
    */
    if (tmp.weap ==(1 << n_boss) -1) {
      cout<< tmp.cost;
      return tmp.cost;
    }
    /* 
    For all bosses kill the one requiring least shots
    among the weapon(s) we have
    */
    for (int i = 0; i < n_boss; ++i) {
    // If we have this weapon than we have already killed this boss
      if ((tmp.weap >> i) & 1) continue;
      int best =health[i];
      for (int j = 0; j < n_boss; ++j) {
        if (i ==j) continue;
        // Check if we have this weapon and it does some damage
        if (((tmp.weap >> j) & 1) && damage[j][i] != '0') {
          int shots =health[i]/(damage[j][i] -'0');
          if (health[i]%(damage[j][i] -'0') != 0) shots++;
          best =min(shots, best);
        }
      }
      // Add this node to the queue
      node tmp1;
      tmp1.weap= (tmp.weap | (1 << i));
      tmp1.cost =tmp.cost +best;
      pq.push(tmp1);
    }
  }
  return 0;
}
