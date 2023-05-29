#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

/*

Type: Dp Tabulation
1. How many states will be there in my dp ?
-> 1D array.

2. What does each state in my dp represent ?
-> dp[i][j] represents the minimum cost for ith day performing jth activity

3. How do we transition to new state, i.e how do we compute dp[i][j]  using previous values ?
-> dp[i][j] = cost[i][j] + max(dp[i-1][j+1], dp[i-1][j+2])

*/

void run()
{
  int n, w;

  cin >> n >> w;

  vector<pair<int, int>> ins(n + 1);

  for (int i = 1; i <= n; i++)
  {
    int a, b;
    cin >> a >> b;
    ins[i] = make_pair(a, b);
  }

  vector<vector<int>> dp(n + 1, vector<int>(w + 1));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      if (j < ins[i].first)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        int to_add = ( j - ins[i].first == ins[i].first) ? 0 : dp[i][j-ins[i].first];
        dp[i][j] = max(dp[i - 1][j], ins[i].second + to_add);
      }
    }
  }

  cout << "DONE" << endl;
}

int main()
{

  // cin.tie(0);
  // cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  run();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
