#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

ll dp[200005];

ll fact(int a ) {


	if(a==0 || a == 1){
		return 1;		
	}

	return  a * fact(a-1);
}



void run() {
	
	ll n;

	cin>>n;

	int a[n];
	int b[n];

	vector<ll> bucka(n+1);
	vector<ll> buckb(n+1);

	for(int i=0;i<n;i++) {

		int l,r;
		cin>>l>>r;

		a[i] = l;
		b[i] = r;

		bucka[l]++;
		buckb[r]++;
	}

	ll ansl = (n * (n-1) * (n-2))/6;

	
	for(int i=0;i<n;i++) {

		ll dx = bucka[a[i]]-1;
		ll dy = buckb[b[i]]-1;

		ansl -= (dx * dy);
		

	}

	

	cout<<ansl<<endl;
	
}

int main() {

  // ios::sync_with_stdio(0);
  // cin.tie(0);
  //cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  int t;
  cin>>t;

  while(t-->0){
  	run();
  }
}
