#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

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
  int t;

  cin >> t;

  while (t-- > 0)
  {
    ll n, k, b, s;

    cin >> n >> k >> b >> s;

    ll bk = k * (b+1);
    bk = min(bk-1, s);
    

    if (bk / k != b) {
      cout<<-1<<endl;
      continue;
    }

    vector<ll> a(n);

    a[0] = bk;

    ll req = s - bk;

    if (req < 0)
    {
      cout << -1 << endl;
      continue;
    }

    bool is_possible = ceil(req / n - 1) <= k - 1;

    ll total = bk;

    if (is_possible)
    {
      for (int i = 1; i < n; i++)
      {
        if (total == s) {
          break;
        }

        a[i] = min(k - 1, s - total);
        total += a[i];
      }
    }

    if (total != s)
    {
      cout << -1;
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        cout << a[i] << " ";
      }
    }

    cout << endl;
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
