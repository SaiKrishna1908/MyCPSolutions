/*
Consider a money system consisting of n coins. Each coin has a positive integer value.
Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF (ll)1e9 + 7
#define MAXN 1e6

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

/*
  Type: Bottom up DP

  1. How many states will be there in my dp ?
  -> 1

  2. What does each state in my dp represent ?
  -> dp[i] represents the minimum number of coins needed to form i.

  3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?
  -> dp[i] = min(dp[i], dp[i - coin[j]] + 1)
*/

void run()
{
  int n, x;

  cin >> n >> x;

  vector<ll> dp(x + 1);
  vector<int> coins(n);

  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  fill(dp.begin(), dp.end(), INF);

  dp[0] = 0;

  // for each sum possible
  for (int i = 1; i <= x; i++)
  {
    // for each coin
    for (int j = 0; j < n; j++)
    {
      if (coins[j] <= i)
      {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }

  cout << (dp[x] == INF ? -1 : dp[x]) << endl;
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
