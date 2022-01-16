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


  int t;

  cin>>t;

  while(t-->0){


    int n;
    cin>>n;

    switch(n%4) {

    case 0: cout<<"1 "<<n<<"\n";
      break;

    case 1: cout<<"1 "<<"1\n";
      break;

    case 2: cout<<"2 "<<n<<" 1"<<"\n";
      break;

    default: cout<<"0"<<"\n";
    }      
  } 
}
