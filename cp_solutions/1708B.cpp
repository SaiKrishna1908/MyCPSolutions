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

  cin>>t;

  while (t-- > 0)
  {
    int n, l, r;

    cin >> n >> l >> r;

    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
      double div = ((l - 1) / i);
      int num = (div + 1) * i;

      if (num > r)
      {
        break;
      }
      res.push_back(num);
    }

    if (res.size() < n)
    {
      cout << "NO" << endl;
      continue;
    }
    else
    {
      cout << "YES" << endl;
      for (int i = 0; i < res.size(); i++)
      {
        cout << res[i] << " ";
      }      
    }
    cout<<endl;
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
