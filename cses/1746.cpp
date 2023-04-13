#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

const ll MOD = 1e9+7;

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

  int n, m;

  cin >> n >> m;

  vector<int> v(n + 1);

  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }

  /*
    How many states my dp has ?
    -> This dp has 2 states

    What does each state represent in my dp ?
    -> dp[i][j] represent number of paths from ith node to j.    
  */

  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));

  if (v[1] == 0)
  {
    for (int i = 1; i <= m; i++)
    {
      dp[1][i] = 1;
    }
  }
  else
  {
    dp[1][v[1]] = 1;
  }

  for (int i = 2; i <= n; i++)
  {

    if (v[i] != 0)
    {
      if (v[i] == 1)
      {
        dp[i][v[i]] = (dp[i - 1][v[i]] + dp[i - 1][v[i] + 1])%MOD;
      }
      else if (v[i] == m)
      {
        dp[i][v[i]] = (dp[i - 1][v[i] - 1] + dp[i - 1][v[i]])%MOD;
      }
      else
      {
        dp[i][v[i]] = ((dp[i - 1][v[i] - 1] + dp[i - 1][v[i]]) + dp[i - 1][v[i] + 1])%MOD;
      }
    }
    else
    {
      for (int j = 1; j <= m; j++)
      {

        if (j - 1 > 0 && m - j > 0)
        {
          dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) + dp[i - 1][j + 1])%MOD;
        }
        else
        {
          if (j == 1)
          {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1])%MOD;
          }
          else if (j == m)
          {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%MOD;
          }
        }
      }
    }
  }

  if (v[n] != 0) {
    cout << dp[n][v[n]] << endl;
  } else {
    ll sol = 0;

    for(int i=1;i<=m;i++) {
      sol =  (sol + dp[n][i])%MOD;
    }

    cout<<sol<<endl;
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
