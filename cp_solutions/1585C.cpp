#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
  int n,k;

  cin>>n>>k;

  vector<ll> pos;
  vector<ll> neg;

  for(int i=0;i<n;i++) {

    ll temp;
    cin>>temp;

    if(temp < 0) {
      neg.push_back(temp);
    } else {
      pos.push_back(temp);
    }

  }

  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  reverse(pos.begin(), pos.end());
  reverse(neg.begin(), neg.end());

  ll res = 0;

  ll mx = 0;

  for(int i=0;i<pos.size();i+=k) {
    res += 2*pos[i];
    mx = max(mx, pos[i]);
  }

  for(int i=neg.size()-1;i>=0;i-=k) {
    res += 2*abs(neg[i]);
    mx = max(mx, abs(neg[i]));
  }

  res-=mx;

  cout<<res<<endl;
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
