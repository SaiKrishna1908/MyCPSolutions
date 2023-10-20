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

  ll n,a,x;

  cin>>n;
  cin>>a;
  cin>>x;
  
  // no of ones
  ll b = n-a;

  ll k = (x/b);


  if(b*a < x)
    cout<<-1;
     
  else{      

    for(int i=0;i<a-k-1;i++)
      cout<<"0 ";
    for(int i=0;i<x%b;i++)
      cout<<"1 ";

    cout<<"0 ";

    for(int i=0;i<b-(x%b);i++)
      cout<<"1 ";
    for(int i=0;i<k;i++)
      cout<<"0 ";
  }
}
