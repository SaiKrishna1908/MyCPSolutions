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
  int n, x;

  cin >> n >> x;

  vector<int> v(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  int i = 0, j = 0;
  ll sum = 0;

  int count = 0;

  bool is_completed = false;

  while (i < n)
  {
    sum += v[i];

    while(sum>=x) {
      if (sum == x) {
        count++;
      }

      sum-=v[j];
      j++;
    }

    i++;
  }

  cout << count << endl;
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
