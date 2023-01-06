#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

ll mod = 1000000007;

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int t;

  cin>>t;  

  while(t-->0) {
    ll n;

    cin>>n;

    bool go_h=true;

    int i =1, j=1;

    ll sum = 1;

    for(ll idx=0;idx<(2 * n -1);idx++) {

      if (i==n && j==n) {
        break;
      }
      if (go_h) {
        j++;
      } else {
        i++;
      }
      go_h= !go_h;
      sum = (sum%mod + (i * j)%mod)%mod;
    }
    cout<<((sum * 2022) % mod )<<endl;
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
