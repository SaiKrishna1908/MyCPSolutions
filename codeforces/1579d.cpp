#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){

	if (a.second > b.second)
		return true;

	return false;

}


void print(vector<pair<int,int>> vec) {

	for(auto i : vec) {
		cout<<i.second<<" ";
	}

	cout<<endl;
}

// bool isZero(pair<int,int> a) {

// 	cout<<a.second<<endl;
// 	return (a.second == 0);
// }

void solve() {

	int n;

	cin>>n;

	vector<pair<int,int>> a;

	vector<pair<int,int>> meetings;

	int max_meetings = 0;

	int running_diff = 0;

	for (int i=0;i<n;i++) {

		int temp;
		cin>>temp;
		a.push_back(make_pair(i,temp));
		
	}


	 sort(a.begin(), a.end(), compare);	

	// for (auto i : a){
	// 	cout<<"<"<<i.second<<","<<i.first<<">"<<" ";
	// }


	while(a.size() > 1) {

		// cout<<a.size();

		
		auto v1 = *a.begin();
		a.erase(a.begin());
		auto v2 = *a.begin();
		a.erase(a.begin());

		if (v1.second !=0 and v2.second !=0 )
			meetings.push_back(make_pair(v1.first+1, v2.first+1));

		if (v1.second > 1 ) {
			a.push_back(make_pair(v1.first, v1.second-1));
		}

		if (v2.second > 1){
			a.push_back(make_pair(v2.first, v2.second-1));
		}

		
		sort(a.begin(), a.end(), compare);			
	}


	cout<<meetings.size()<<endl;

	for(auto res : meetings) {
		cout<<res.second<<" "<<res.first<<endl;
	}

}

int main() {

	cin.tie(0);
	cout.sync_with_stdio(false);

	int  t;

	cin>>t;

	while(t-->0){
		solve();
	}

	return 0;
}