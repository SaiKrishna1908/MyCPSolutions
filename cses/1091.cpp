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
  int n,m;

  cin>>n>>m;

  multiset<int> tck_price;

  

  for(int i=0;i<n;i++) {
    int input;
    cin>>input;
    tck_price.insert(input);    
  }  

  for(int i=0;i<m;i++) {
    int m;

    cin>>m;
    
  
    auto itr = tck_price.upper_bound(m);

    // He cannot afford any ticket
    if (itr == tck_price.begin()) {
      cout<<-1<<endl;
    } else {
      cout<< * (--itr)<<endl;
      tck_price.erase(itr);
    }             
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