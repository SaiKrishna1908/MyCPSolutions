#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {

	string s;

	cin>>s;

	int a[] = {0,0};



	for(char c : s) {

		a[c-'0']++;


		if ( (a[1]>0) and (a[0]>0) ) {
			cout<<2<<endl;
			return;
		}		
	}

	if(a[0]) {
		cout<<1<<endl;
	}

	else {
		cout<<0<<endl;
	}

	
}


int main() {

	int t;

	cin>>t;

	while(t--> 0 ){
		solve();
	}

	return 0;
}