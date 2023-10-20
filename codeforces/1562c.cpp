#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  int n;

  cin>>n;

  string c;


  cin>>c;

  for(int i=0;i<n;i++) {

    if ( c[i] == '0' ) {

      if ( i >= n/2 ) {
	cout << 1 <<" "<<i+1<<" "<<1<<" "<<i<<endl;	
      }
      else {

	cout << i+1 <<" "<< n <<" "<<i<<" "<<n<<endl;
      }

      return;
    }
  }

  cout<<1<<" "<<(n-1)<<" "<<2<<" "<<n<<endl;
}

int main() {

  // ios::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  int t;

  cin>>t;

  while(t-->0) {
    run();
  }
}
