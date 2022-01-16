#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout<<fixed;
  cout<<setprecision(10);

  int n;
  cin>>n;

  ll a[n], b[n];

  ll product = 0 ;

  for(int i=0;i<n;i++)
    cin>>a[i];

  for(int i=0;i<n;i++)
    cin>>b[i];

  for(int i=0;i<n;i++)
    product+=a[i]*b[i];


  ll max = product;

  // Odd sequenece
  for(int cntr=0;cntr<n;cntr++){

    ll total = product;
    for(int l=cntr-1, r=cntr+1; l>=0 && r<n;l--,r++){
      total-= (a[l]*b[l] + a[r]*b[r]);
      total+= (a[r]*b[l] + a[l]*b[r]);

      max = std::max(total,max);
    }
  }

  for(int i=0,j=1;j<n;i++,j++){

    ll total = product;

    for(int l=i,r=j;l>=0 && r<n;l--,r++){

      total-=(a[l]*b[l] + a[r]*b[r]);
      total+=(a[r]*b[l] + a[l]*b[r]);

      max = std::max(total,max);
    }
  }

  cout << max;

  return 0;
}
