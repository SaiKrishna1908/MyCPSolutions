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

/*
  Choose Median instead of Mean, because median gives 
  elements that are already present in the array thus 
  making it possible to obtain the minimum answer
*/

void run() {
  int n;

  cin>>n;

  vector<ll> v(n);

  

  for(int i=0;i<n;i++) {
    cin>>v[i];    
  }

  sort(v.begin(), v.end());

  ll median = v[n/2];


  ll sum = 0;

  for(int i=0;i<n;i++) {
    sum += abs(median - v[i]);
  }


  cout<<sum<<endl;
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
