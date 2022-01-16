#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main () {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;

  cin>>t;

  while(t-->0) {

    int n;

    cin>>n;

    int MAX = -1;

    while(n != 0) {

      if (n%10 > MAX) {
	MAX = n%10;
	
      }

      n = n/10;       
    }

    cout<<MAX<<"\n";
  }
}
