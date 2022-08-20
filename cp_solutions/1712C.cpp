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

// Expected 6, found 5
void run()
{
  int t;
  cin >> t;

  while (t-- > 0)
  {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    vector<int> freq(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      freq[arr[i]]++;
    }

    int next = INT_MAX;
    int br_point = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {

      if (arr[i] > next)
      {
        break;
      }

      if (freq[arr[i]] == 1)
      {
        br_point = i;
      }

      next = arr[i];
      freq[arr[i]]--;
    }

    int count = 0;
    fill(freq.begin(), freq.end(), 0);

    for (int i = 0; i < br_point; i++)
    {
      freq[arr[i]]++;
    }

    int high = -1;

    for (int i = n - 1; i > br_point; i--)
    {
      if (freq[arr[i]])
      {
        high = i;
        break;
      }
    }

    for (int i = br_point; i < high; i++)
    {
      freq[arr[i]]++;
    }

    for (int i = 0; i < freq.size(); i++)
    {
      if (freq[i] > 0)
      {
        count++;
      }
    }

    cout << count << endl;
  }
}

int main()
{

  cin.tie(0);
  cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  run();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
