#include<bits/stdc++.h>

using namespace std;

#define ll long long;



void solve () {

	int n;

	cin>>n;
	char s[n+1];


	int count =0;

	for(int i=1;i<=n;i++) {
		cin>>s[i];

		if(s[i] != '?') {
			count++;
		}
	}

	if(!count) {
		s[1] = 'B';
	}

	for(int i=2;i<=n;i++) {

		if (s[i] == '?' and s[i-1] != '?') {
			s[i] = s[i-1] ^ ('B' ^ 'R');
		}
	}

	for(int i=n-1;i>0;i--) {
		
		if (s[i] == '?' and s[i+1] != '?') {
			s[i] = s[i+1] ^ ('B' ^ 'R');
		}
	}

	for(int i=1;i<=n;i++) {
		cout<<s[i];
	}

	cout<<endl;

}

int main() {

	cin.tie(0);
	cout.sync_with_stdio(false);

	int t;
	cin>>t;


	while(t-->0) {
		solve();
	}
}
