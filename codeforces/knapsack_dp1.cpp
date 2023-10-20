#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void display(vector<ll> a)
{
  for (int i = 0; i < a.size(); i++)
  {
    cout << (a[i]) << " ";
  }
  cout << endl;
}


void max_self(int &a, int b) {
  a = max(a,b);
}

void run()
{

  int n, w;

  cin >> n >> w;

  // Here dp[i] represents the maximum value which can be obtained with weight i.
  vector<ll> dp(w + 1);

  fill(dp.begin(), dp.end(), 0);

  /*
      transition of dp is as follows:

  */

  for (int i = 0; i < n; i++)
  {
    int weight, value;

    cin >> weight >> value;

   for(int j=w;j>=weight;j--) {
     dp[j] = max(dp[j], (j-weight >= 0 ? dp[j-weight] : 0) + value);
   }     

   display(dp);
  }

  ll answer = 0;

  for(int i=0;i<=w;i++) {
    answer = max(answer, dp[i]);
  }

  cout<<answer<<endl;
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
  return 0;
}
