#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
  int n;


  cin>>n;

  vector<int> a(n);


  for(int i=0;i<n;i++) {
  	cin>>a[i];
  }

  sort(a.begin(), a.end());

  cout<<(a[n-1] - a[0])<<endl;
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

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
