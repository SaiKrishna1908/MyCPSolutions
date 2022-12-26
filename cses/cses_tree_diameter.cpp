#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN 2e5+7

vector<vector<int>> dp(MAXN,vector<int>(2));

int ans = 0;

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

bool is_leaf(vector<vector<int>> *tree, int i) {
    if (tree->at(i).size() == 1 && i != 1) {
        return true;
    }

    return false;
}


void dfs(vector<vector<int>> *tree, int u, int p) {

    vector<int> sub_diameters;

    if (is_leaf(tree, u)) {
        dp[u][0] = 0;
        dp[u][1] = 0;
        return;
    }

    for(auto child : tree->at(u)) {
        if (child == p) continue;
        dfs(tree,child, u);
        sub_diameters.push_back(dp[child][0]);
    }

    sort(sub_diameters.rbegin(), sub_diameters.rend());

    int child_count = sub_diameters.size();

    if (child_count == 1) {
        dp[u][0] = 1 + sub_diameters[0];
        dp[u][1] = 0;
    } else {
        dp[u][0] = 1 + sub_diameters[0];
        dp[u][1] = 1 + sub_diameters[0] + 1 + sub_diameters[1];
    }

    ans = max(ans, max(dp[u][0], dp[u][1]));
}

void run() {
  int n;

  cin>>n;


  vector<vector<int>> v(n+1);

  for(int i=1;i<n;i++) {
    int p, c;
    cin>>p>>c;

    v[p].push_back(c);
    v[c].push_back(p);    
  }

  if (n == 1) {
    cout<<0<<endl;
    return;
  }

  dfs(&v,1, -1);

  cout<<ans<<endl;
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
