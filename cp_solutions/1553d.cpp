#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  string s,t;

  cin >> s;
  cin >> t;

  int i = s.length();
  int j = t.length();

  if ( i < j ) {
    cout<<"NO"<<endl;
    return ;
  }

  while( i >= 0) {
 

      if ( i < 0  or j < 0 ) {

	break;
      }

      if(s[i] != t[j]) {

	i = i-2;
	
      }
      else {

	i=i-1;
	j=j-1;
      }
  }

  if ( j<0 ) {

    cout<<"YES"<<endl;
  }
  else {
    cout<<"NO"<<endl;
  }
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  int t;

  cin>>t;

  while (t--> 0) {

    run();
  }


}
