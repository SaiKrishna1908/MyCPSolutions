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

void run()
{
  int n, x;

  cin >> n >> x;

  vector<ll> dp(x+1);
  vector<int> coins(n);


  for(int i=0;i<n;i++) {
    cin>>coins[i];
  }

  fill(dp.begin(), dp.end(), INF);
  
  dp[0] = 0;
  for(int i=1;i<=x;i++) {
    for(int j=0;j<n;j++) {
      if (coins[j] <= i) {
        dp[i] = min(dp[i], dp[i-coins[j]] + 1);
      }      
    }
  }
  
  cout<<dp[x]<<endl;
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
