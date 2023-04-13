#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7
#define MAXN 1e6+5

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

void run() {
  int n,x;

  cin>>n>>x;

  vector<int> coins(n);
  vector<ll> cdp(MAXN);

  for(int i=0;i<n;i++) {
    cin>>coins[i];
  }

  cdp[0] = 1;
  for(int i=0;i<MAXN;i++) {
    for(auto e : coins) {
      ll sum = e + i;

      if (sum < MAXN) {        
        cdp[sum]= (cdp[sum] + cdp[i])%1000000007;
      }
    }
  }

  cout<<cdp[x]<<endl;
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
