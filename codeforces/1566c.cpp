#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define ll long long



void solve() {

	int n;

	cin>>n;

	vi a(n);

	for(int i=0;i<n;i++) {

		char temp;
		cin>>temp;

		int in = temp-'0';
		a[i] = in;
	}

	for(int i=0;i<n;i++) {
		char temp;
		cin>>temp;

		int in = temp-'0';

		if(in^a[i]) {
			a[i] = 2;
		}
		else {
			if(in == 0){
				a[i] = 1;
			}
			else {
				a[i] = 0;
			}
		}
	}

	int sum=0;



	for(int i=0;i<n;i++) {		
		sum+=a[i];
	}


	for(int i=0;i<n;i++) {
	

		if (a[i] == 0) {
			
			if (i-1 >= 0 && a[i-1] == 1) {
				sum++;
			}

			else if (i+1 < n && a[i+1] == 1){

				cout;
				sum++;
				a[i+1] = 2;
			}
		}

		
	}
		

	cout<<sum<<endl;
}


int main() {

	cin.tie(0);
	cout.sync_with_stdio(false);
	
	int t;

	cin>>t;

	while(t-->0) {
		solve();
	}

	return 0;
}