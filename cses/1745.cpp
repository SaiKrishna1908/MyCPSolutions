#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7
#define MAXN 100007

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

/*
  1. How many dp states do we need ?
  -> 1
  2. What do the state represent
  -> dp[i] is 1 if sum i can be obtained
  3. 
*/
void run()
{
  vector<int> dp(MAXN);

  int n;
  cin >> n;

  vector<int> arr(n + 1);

  int sum = 0;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    sum+=arr[i];
  }

  dp[0] = 1;
  int count = 0;

  for(int i=1;i<=n;i++) {
    for(int j=MAXN;j>=0;j--) {
      int diff = j - arr[i];

      if (diff >=0 && dp[diff]) {        
        dp[j] = 1;
      }
    }
  }

  vector<int> sol;

  for (int i = 1; i <= MAXN; i++)
  {
    if (dp[i])
    {
      sol.push_back(i);
    }
  }

  cout<<sol.size()<<endl;

  print_vec(sol);
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
