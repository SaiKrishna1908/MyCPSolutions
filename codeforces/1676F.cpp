#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void run()
{
  int t;
  cin >> t;

  while (t-- > 0)
  {
    int n, k;
    cin >> n >> k;

    map<long, long> am;

    for (int i = 0; i < n; i++)
    {
      int in;
      cin >> in;
      if (am.find(in) != am.end())
      {
        am[in] += 1;
      }
      else
      {
        am[in] = 1;
      }
    }

    vector<int> far;

    for (auto itr = am.begin(); itr != am.end(); ++itr)
    {
      if ((*itr).second >= k)
      {
        far.emplace_back((*itr).first);
      }
    }

    

    sort(far.begin(), far.end());


    if (!far.size()) {
      cout<<-1<<endl;
      continue;
    }

    int l = 0, r = 0, l_max = 0, r_max = 0;

    for (int i = 1; i < far.size(); i++)
    {
      if (far[i] - far[i - 1] <= 1)
      {
        r++;
      }
      else
      {
        l = i;
        r = i;
      }
      if (r - l > r_max - l_max)
      {
        r_max = r;
        l_max = l;
      }
    }

    cout << far[l_max] << " " << far[r_max] << endl;
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
