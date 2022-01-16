#include <bits/stdc++.h>

using namespace std;

void solve() {


	int n;

	cin>>n;

	auto cmp = [](pair<int,int> const &x, pair<int,int> const &y) {

		return x > y;
	};


	set<pair<int,int>, decltype(cmp)> a(cmp);

	vector<pair<int,int>> answers;
		

	for (int i=0;i<n;i++) {
		int temp;
		cin>>temp;

		if( temp > 0 ) {
			a.emplace(temp,i);
		}		
	}
	

	while(a.size() > 1) {

		auto p1 = *a.begin();
		a.erase(a.begin());
		auto p2 = *a.begin();
		a.erase(a.begin());


		// Push back index of p1 and p2
		answers.push_back(make_pair(p1.second+1, p2.second+1));

		if (p1.first-1>0) {
			a.insert(make_pair(p1.first-1, p1.second));		
		}
		if (p2.first-1>0) {
			a.insert(make_pair(p2.first-1, p2.second));
		}

	}

	cout<<answers.size()<<endl;

	for (auto i: answers) {
		cout<<i.first<<" "<<i.second<<endl;
	}

}


int main() {

	// cin.tie(0);
	// cout.sync_with_stdio(false);


	int t;
	cin>>t;

	while(t-->0) {	
		solve();
	}

	return 0;
}