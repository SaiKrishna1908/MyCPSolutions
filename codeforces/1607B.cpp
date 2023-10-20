#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
  ll n,t;

  cin>>n>>t;

  // at tm we will have i = i
  ll tm = t - (t%4);

  for(ll i=tm+1;i<=t;i++) {
    n = (n%2 == 0) ? (n-i) : (n+i);
  }

  cout<<n<<endl;
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

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
