#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int n;
  cin>>n;

  int positions[n+1];

  for(int i=1;i<=n;i++) {
    int elem;
    cin>>elem;

    positions[elem] = i;
  }

  int round = 0;
  int curr_element = 1;
  int prev_element_index = positions[curr_element];

  while(curr_element <= n) {
    if (prev_element_index >= positions[curr_element]) {
      round++;
    }    
    prev_element_index = positions[curr_element];
    curr_element++;    
  }

  cout<<round<<endl;
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
