#include <bits/stdc++.h>

using namespace std;


void solve() {

	int n;	

	int sum = 0;
	cin>>n;

	vector<int> a(n);
	map<int,int> map;

	for (int i=0;i<n;i++) {

		int temp;
		cin>>temp;
		a[i] = temp;
		map[temp] = map[temp]+1;

		sum+=temp;

	}		


	if ( ((2*sum)%n) != 0) {
		cout<<0<<endl;
		return;
	}

	int req = (2*sum)/n;
	int ans = 0;

	// for(auto i: map) {
	// 	cout<<"("<<i.first<<","<<i.second<<")"<<" ";
	// }

	// cout<<endl;

	for (int i=0;i<n;i++) {

		int ai = a[i];
		int aj = req - ai;

		// cout<<aj<<" ";

		if (map[aj]) {
			ans += map[aj];
		}

		if (ai == aj) {
			ans--;
		}
	}

	cout<<ans/2<<endl;

	// cout<<endl;
}

int main() {

	// cin.tie(0);
	// cin.sync_with_stdio(false);


	int t;

	cin>>t;

	while(t--> 0) {
		solve();
	}
}