#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

ll dpsumone[200005];

int max = 200005;

void precalc(int n) {

  dpsumone[1] = 0;
  
  for(int i=2;i<n;i++) {

    dpsumone[i] = dpsumone[i-1] + 1;
    
  }


  int sum =0;

  for(int i=0;i<sqrt(n);i++) {

    sum+= 
  }
    
}

void run() {

  dpsumone

  int n;

  ll mod;

  cin>>n;
  cin>>mod;

  for (int 
  
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  run();
}
