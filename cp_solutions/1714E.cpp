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
  // If we have 5 we can only apply transformation once
  int t;

  cin >> t;

  while (t-- > 0)
  {
    int n;
    cin >> n;

    vector<int> arr(n);

    bool flag5 = false;

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];

      // If arr[i] is divisible 5 we can apply a operation atmost once
      if (arr[i] % 5 == 0)
      {
        flag5 = true;
        arr[i] = arr[i] + (arr[i] % 10);
      }
    }

    if (flag5)
    {
      bool isEqual = (*min_element(arr.begin(), arr.end()) == *max_element(arr.begin(), arr.end()));
      isEqual ? cout << "Yes" << endl : cout << "No" << endl;
      continue;
    }
    else
    {

      for (int i = 0; i < n; i++)
      {
        int x = arr[i];

        while (x % 10 != 2)
        {
          x = x + (x % 10);
        }
        arr[i] = x;
      }

      sort(arr.begin(), arr.end());

      bool can = true;

      for (int i = 1; i < n; i++)
      {
        if (arr[i] != arr[i - 1] && (arr[i] - arr[i - 1] < 20))
        {
          can = false;
        }
      }

      can ? cout << "YES" << endl : cout << "NO" << endl;
    }
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
