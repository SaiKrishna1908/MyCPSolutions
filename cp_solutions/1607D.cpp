#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
  int n;

  cin>>n;

  vector<int> arr(n);

  vector<int> blue,red;

  for(int i=0;i<n;i++) {
    cin>>arr[i];
  }

  char c[n];
  cin>>c;

  for(int i=0;i<n;i++) {
    (c[i] == 'B' ? blue :red).push_back(arr[i]);
  }

  sort(all(blue));
  sort(all(red), greater<int>());

  // cout<<"Blue"<<endl;
  // for(auto i : blue) {
  //   cout<<i<<endl;
  // }

  // cout<<"Red"<<endl;
  // for(auto i : red) {
  //   cout<<i<<endl;
  // }

  bool ans = true;

  for(int i=0;i<blue.size();i++) {

    // we cannot increase blue
    if(blue[i] < i+1) {
      ans = false;
    }
  }

  for(int i=blue.size();i<n;i++) {
    // we cannot decrease red
    if(red[n-i-1]>i+1) {
      ans= false;
    }
  }

  cout<<(ans ? "YES" : "NO")<<endl;
  
}

int main() {

    // cin.tie(0);
  // cin.sync_with_stdio(false);
    

auto start = high_resolution_clock::now();
  
  int t;
  cin>>t;

  while(t-->0) {  
    run();
  }
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);



  //  cout<<"time: "<<duration.count()/1e6<<endl;
}
