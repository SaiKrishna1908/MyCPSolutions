#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> v;

void pre_calc() {

  v.push_back(11);

  for(int i=1;i<11;i++) {

    ll nxt = v[i-1]*10 + 1;

    v.push_back(nxt);
  }
  
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;

  cin>>t;




  while( t--> 0) {

    int n;

    cin>>n;

    for(int i=0;i<20;i++){

      if(n%11 == 0) {

	cout<<"YES"<<"\n";
	goto done;
      }

      n-=111;

      if(n<0) {
	break;
      }
	
    }
    cout<<"NO"<<"\n";

  done:;

  }
  
}
