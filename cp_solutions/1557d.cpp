#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  


  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> v(n);
  vector<int> id;
  while (m--) {
    int i, l, r;
    cin >> i >> l >> r;
    id.push_back(l);
    id.push_back(r);
    v[i - 1].push_back({ l,r });
  }
  sort(all(id));
  id.erase(unique(all(id)), id.end());

  for(auto i : id){

    cout<<i<<endl;
  }

  cout<<"Before"<<endl;

  for (int i=0;i<n;i++) {
    for (auto& it : v[i]) {
      cout<<it.first<<", "<<it.second<<endl;
    }
  }

  for (int i = 0; i < n; i++)
    for (auto& it : v[i]) {
      it.first = upper_bound(all(id), it.first) - id.begin();
      it.second = upper_bound(all(id), it.second) - id.begin();
    }

  cout<<"After"<<endl;
  for(int i=0;i<n;i++) {
    for (auto& it : v[i]) {
      cout<<it.first<<", "<<it.second<<endl;
    }
  }
  
}
