#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


ll cnt(ll a) {

  return a* 1ll * (a+1)/2;
}

void run() {
  
  ll k,x;
  cin>>k>>x;

  ll low = 1;
  ll high = 2*k-1;
  ll result = 2*k-1; 

  bool flag = false;

  while(low <= high) {

    int mid = (low + high) >> 1;

    if (mid >= k ){
      flag = (cnt(k)+cnt(k-1)-cnt(2*k-1-mid) >= x);
    } else {
      flag = (cnt(mid) >= x);
    }

    if(flag) {
      result = mid;
      high = mid - 1;
    } else {
      low = mid+1;
    }
  }
  
  cout<<result<<endl;
}

int main() {

    // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  // auto start = high_resolution_clock::now();

  int t;

  cin>>t;

  while(t-->0) 
    run();
  
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
