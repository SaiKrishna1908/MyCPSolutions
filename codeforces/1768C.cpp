#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN 20005

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
	// ra, rb are used to check if a element has been used or not
	int a[MAXN], b[MAXN], c[MAXN], ra[MAXN], rb[MAXN];
	int n;
  	cin >> n;
	vector<pair<int, int> > V;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		a[i] = b[i] = 0;
		ra[i + 1] = rb[i + 1] = 1;
		V.push_back(make_pair(c[i], i));
	}
	sort(V.rbegin(), V.rend());
	
	for (int i = 0; i < n; i++)
	{
		int k = V[i].second;
		if (ra[c[k]] == 1) a[k] = c[k], ra[c[k]]--;
		else b[k] = c[k], rb[c[k]]--;
	}
	
	int r1 = n, r2 = n;
	for (int i = 0; i < n; i++)
	{
		int k = V[i].second;
		if (a[k] == 0)
		{
			while (ra[r1] == 0) r1--;
			ra[r1]--;
			if (r1 > b[k])
			{
			    cout << "NO" << '\n';
			    return;
			}
			a[k] = r1--;
		}
		else
		{
			while (rb[r2] == 0) r2--;
			rb[r2]--;
			if (r2 > a[k])
			{
			    cout << "NO" << '\n';
			    return;
			}
			b[k] = r2--;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ra[i] != 0 || rb[i] != 0)
		{
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();

  int t;
  cin>>t;

  while(t-->0) {
	run();
  }    
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
