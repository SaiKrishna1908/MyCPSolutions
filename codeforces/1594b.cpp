#include <bits/stdc++.h>


#define ll long long


using namespace std;


long MOD = 1e9+7;



void solve() {

	ll n,k;

	cin>>n>>k;


	ll tk = k;

	ll sum = 0;
	ll power = 1;

	while (tk > 0) {


		if(tk & 1) {
			sum =  (sum + power)%MOD;
		}

		power*=n;

		power %= MOD;

		tk = tk>>1;
		
	}	


	cout<<sum<<endl;
	
}



int main() {

	// cin.tie(0);
	// cout.sync_with_stdio(false);


	int t;

	cin>>t;

	while(t-->0) {
		solve();
	}
}