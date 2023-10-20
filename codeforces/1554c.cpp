#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define MAX 10e9



void run() {

  ll n,m;

  cin>>n>>m;

  ++m;

  ll ans = 0;

  for(int k=30;k>=0 && n<m;k--) {

    if( (n>>k & 1) == (m>>k & 1 ))
      continue;

    if( (m>>k & 1)) {
      ans |= 1 << k;
      n |= 1 << k;
    }
  }

  cout << ans<<endl;
}


int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);


  int t;

  cin >> t;

  while(t-->0) {
    run();
  }
}
