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

  ll v2n = 0;
  ll v5n = 0;

  ll i2 = 2;
  ll i5 = 5;

  while(i2 <= n) {
    v2n += floor(n/i2);
    i2*=2;
  }

  while(i5<=n) {
    v5n += floor(n/i5);
    i5*=5;
  }

  cout<<min(v2n, v5n)<<endl;
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
