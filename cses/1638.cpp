#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7
#define MAXN 1007

vector<vector<ll>> dp(MAXN, vector<ll>(MAXN));
vector<vector<int>> graph(MAXN, vector<int>(MAXN));

int n;

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

bool isValid(int i, int j)
{
  if (i >= n || j >= n)
  {
    return false;
  }
  else if (i < 0 || j < 0)
  {
    return false;
  }
  else if (graph[i][j] == 0)
  {
    return false;
  }
  return true;
}

ll solve(int i, int j)
{
  if (!isValid(i, j))
  {
    return 0;
  }
  if (i == n - 1 && j == n - 1)
  {
    return 1;
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  dp[i][j] = (solve(i + 1, j) + solve(i, j + 1)) % 1000000007;
  return dp[i][j];
}

void run()
{
  cin >> n;  

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      char c;
      cin >> c;

      graph[i][j] = (c == '.') ? 1 : 0;
      dp[i][j] = -1;
    }
  }

  if (n == 1) {
    if (graph[0][0]) {
      cout<<1<<endl;
      
    } else {
      cout<<0<<endl;
    }
    return;
  }

  solve(0, 0);

  if (dp[0][0] == -1) {
    cout<<0<<endl;
  } else {
    cout << dp[0][0] << endl;
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
