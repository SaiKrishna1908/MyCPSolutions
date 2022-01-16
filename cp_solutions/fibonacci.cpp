#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {



  int n;

  cin>>n;

  if(n == 1) {
    cout<<0;
    return;
  }


  vector<int> a;

  a.push_ba
  ck(0);
  a.push_back(1);

  n-=2;

  while(n-->0) {

    int first = a[a.size()-2];
    int second = a[a.size()-1];

    a.push_back(first+second);
  }
  
  cout<<a[a.size()-1];
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  run();
}
