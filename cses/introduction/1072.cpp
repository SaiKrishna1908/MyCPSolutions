#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}
/*
  using I/E principle

  ans = (# ways of placing two knights on n * n chess board) - 
  (# ways of placing two knights on n*n chess board such that they attack each other)

  To find number of ways two knights kill each other.

  A knight kills other knight if they form a 2x3 or 3x2 matrix

  So, we just need to find the number of ways of placing a 2x3 matrix  + 3x2 matrix in the chessboard
*/

void run() {
  int n;

  cin>>n;

  for(int i=1;i<=n;i++){
    ll boxes = i * i;

    ll ncr = (boxes * (boxes - 1))/2;


    ll place_to_kill = 4 * ((i - 1) * (i - 2));     

    cout<<(ncr - place_to_kill)<<endl;
  }
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
