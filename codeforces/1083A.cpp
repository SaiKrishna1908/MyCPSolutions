#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN 3e5+7

ll ans = 0;

vector<vector<ll>> dp(MAXN, vector<ll>(2));
vector<int> weights(MAXN);

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

bool is_leaf_node(vector<vector<pair<int,int>>> *t, int u) {
  if (t->at(u).size() == 1 && u != 1 ) {
    return true;
  }

  return false;
}

void dfs(vector<vector<pair<int,int>>> *t, int u, int p) {
  vector<ll> child_dist;

  if (is_leaf_node(t, u)) {
    dp[u][0] = weights[u];
    dp[u][1] = 0;
    ans = max(ans,dp[u][0]);
    return;
  }

  for(auto v : t->at(u)) {
    if (p == v.first) continue;

    dfs(t, v.first, u);    
    child_dist.push_back(max(0ll, dp[v.first][0] - v.second));
  }

  sort(child_dist.rbegin(), child_dist.rend());

  dp[u][0] = (weights[u] + child_dist[0]);

  int child_count = child_dist.size();

  if (child_count == 1) {
    dp[u][1] = 0;
  } else {
    dp[u][1] = (weights[u] + child_dist[0] + child_dist[1]);
  }

  ans = max(ans, max(dp[u][0], dp[u][1]));
}


void run() {
  int n;

  cin>>n;
  vector<vector<pair<int,int>>> edges(n+1);

  for(int i=1;i<=n;i++) {    
    cin>>weights[i];
  }

  if (n==1) {
    cout<<weights[1]<<endl;
    return;
  }

  for(int i=1;i<n;i++) {
    int u,v,c;
    cin>>u>>v>>c;

    edges[u].push_back(make_pair(v,c));
    edges[v].push_back(make_pair(u,c));    
  }


  dfs(&edges, 1 , -1);

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
