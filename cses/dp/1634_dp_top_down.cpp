#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
using namespace std::chrono;
 
#define ll long long
#define all(v) v.begin(), v.end()
#define INF (ll)1e9 + 7
#define MAXN 1e6
 
vector<ll> dp(MAXN);
vector<int> coins;
 
void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

/*
  Type: Memoization DP

  Dp is used to store already computed solution

  1. How many states will be there in my dp ?
  -> 1

  2. What does each state in my dp represent ?
  -> dp[i] represents the minimum number of coins needed to form i

  3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?
  -> for coin in coins:
  ->    steps = mins(steps, solve(n-coin))
*/
 
ll solve(int n)
{  
 
  if (n == 0)
  {
    return 1;
  }
 
  if (dp[n] != 0) {
    return dp[n];
  }
 
  ll steps = INF;
 
  for (auto e : coins)
  {
    if (e <= n)
    {
      steps = min(steps, solve(n - e));
    }
  }
  
  dp[n] = (steps == INF  ? INF : steps+1);
  return dp[n];
}
 
void run()
{
  int n, x;
 
  cin >> n >> x;
 
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
 
    coins.push_back(temp);
  }
 
  auto ans = solve(x);
 
  if (ans == INF) {
    cout<<-1<<endl;
  } else {
    cout<<ans-1<<endl;
  }  
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