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

void run()
{
  int n;
  cin >> n;

  vector<ll> v(n+1);

  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }

  ll dp[n + 1][n + 1];

  ll sum=0;

  for (int i = 1; i <= n; i++)
  {
    dp[i][i] = v[i];
    sum+=v[i];
  }

  for (int jump = 1; jump < n; jump++)
  {
    for (int i = 1; (i + jump) <= n; i++)
    {
      int j = i + jump;
      dp[i][j] = max(v[i] - dp[i+1][j], v[j] - dp[i][j-1]);
    }
  }

  ll ans = (sum + dp[1][n])/2;
  cout << ans << endl;
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
