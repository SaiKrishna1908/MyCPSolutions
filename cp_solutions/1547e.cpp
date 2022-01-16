
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

ll inf=10e12;

void run() {

  int n,k;

  cin>>n>>k;

  vector<ll> pos(k);
  vector<ll> temp(k);

  vector<ll> c(n+1, inf);
  vector<ll> L(n+1, inf);
  vector<ll> R(n+1,inf);
  
  for(int i=0;i<k;i++) {
    cin>>pos[i];
  }

  for(int i=0;i<k;i++) {
    cin>>temp[i];
  }

  for(int i=0;i<k;i++) {
    c[pos[i]] = temp[i];
  }

  for(int i=1;i<=n;i++) {
    c[i] = min(c[i-1]+1, c[i]);
    L[i] = c[i];
  }

  for(int i=n-1;i>=0;i--) {
    
    c[i] = min(c[i+1]+1, c[i]);
    R[i] = c[i];
  }

  for(int i=1;i<=n;i++) {
      cout<<min(L[i], R[i])<<" ";
  }
  cout<<endl;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  int t;
  cin>>t;

  while(t-->0) {
    run();
  }

  return 0;
}
