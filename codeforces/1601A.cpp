#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


ll gcd(ll a, ll b) {

  if(a==0) {
    return b;
  }

  return gcd(b%a, a);
}


void run() {

  int n;

  cin>>n;

  vector<ll> a(n);
  set<ll> ans;

  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  for(int i=0;i<30;i++) {

    int count=0;
    

    for(int j=0;j<a.size();j++) {

      if(a[j]>>i & 1) {
        count++;
      }
    }

    if (count!=0)
      ans.insert(count);
    
  }

  // for(auto i : ans) {
  //   cout<<i<<" ";
  // }

  // cout<<endl;

  for(int i=1;i<=n;i++) {

    bool flag = true;
    for(auto itr = ans.begin();itr!=ans.end();itr++) {

      if(*itr %i != 0) {
        flag = false;
        break;
      }

    }

    if(flag) {
      cout<<i<<" ";
    }

  }

  cout<<endl;
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

// auto start = high_resolution_clock::now();

  int t;

  cin>>t;

  while(t-->0) {
    run();
  }
  
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
