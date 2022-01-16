#include <bits/stdc++.h>

using namespace std;

#define ll long long


void solve() {

	

	int n,x;
	cin>>n>>x;
	vector<int> a(n);

	for(int i=0;i<n;i++){		
		cin>>a[i];
	}

	vector<int> sa(n);	

	sa.assign(a.begin(), a.end());

	sort(sa.begin(), sa.end());

	// if (n >= 2 * x){
	// 	cout<<"YES"<<endl;
	// }
	
	// else {

		for(int i=0;i<n;i++) {
			if(i - x < 0 && i+x > n-1) {
				if(a[i] != sa[i]){
					cout<<"NO"<<endl;
					return;
				}
			}
		}

		cout<<"YES"<<endl;
	// }
	return ;

}

int main() {

	cout.sync_with_stdio(false);
	cin.tie(0);


	int t;

	cin>>t;

	while(t-->0) {
		solve();
	}

	return 0;
}