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
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> dmin(n + 1);
    vector<int> dmax_index(n + 1);

    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
      cin >> b[i];
    }

    dmax_index[n] = n;

    for (int i = n; i >= 1; i--)
    {
      if (a[i] > b[i - 1])
      {
        dmax_index[i - 1] = i - 1;
      }
      else
      {
        dmax_index[i - 1] = dmax_index[i];
      }
    }

    // perform binary search to get the lowest number

    for (int i = 1; i <= n; i++)
    {
      int low = 1;
      int high = n;

      int mid = 0;

      bool number_exists = false;

      while (low <= high)
      {
        mid = low + (high - low) / 2;

        if (a[i] < b[mid])
        {
          high = mid - 1;
        }
        else if (a[i] > b[mid])
        {
          low = mid + 1;
        }
        else if (a[i] == b[mid])
        {
          number_exists = true;
          break;
        }
      }

      if (number_exists)
      {
        dmin[i] = 0;
      }
      else
      {

        if (b[low] - a[i] > 0)
        {
          dmin[i] = b[low] - a[i];
        }

        if (b[high] - a[i] > 0)
        {
          dmin[i] = min(dmin[i], b[high] - a[i]);
        }
      }
    }

    for (int i = 1; i <= n; i++)
    {
      cout << dmin[i] << " ";
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
      cout << b[dmax_index[i]] - a[i] << " ";
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
