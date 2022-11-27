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

    int n, m;
    cin >> n >> m;    

    vector<int> unhappiness(n + 1);

    for (int i = 1; i <= n; i++)
    {
      cin >> unhappiness[i];
    }

    vector<pair<int, int>> fmap(m + 1);
    map<int, vector<int>> g;

    int bucket[n+1];

    for (int i = 1; i <= m; i++)
    {
      int l, r;

      cin >> l >> r;

      fmap[i] = make_pair(l, r);

      bucket[l]++;
      bucket[r]++;

      g[l].push_back(r);
      g[r].push_back(l);
    }

    if (m % 2 == 0)
    {
      cout << 0 << endl;
      continue;
    }

    int min_odd_cost = INT_MAX;

    for(auto val : g) {
      int connections = val.second.size();

      if (connections%2) {
        int cost = unhappiness[val.first];

        if (cost < min_odd_cost) {
          min_odd_cost = cost;
        }
      }      
    }

    // cost to remove all

    int cost_to_remove_all = INT_MAX;

    for (int i = 1; i <= m; i++)
    {      
      auto pair = fmap[i];

      if (g[pair.first].size() % 2 ==0 && g[pair.second].size() %2 ==0) {
        cost_to_remove_all = min(cost_to_remove_all, unhappiness[pair.first] + unhappiness[pair.second]);
      }            
    }


    cout<<min(min_odd_cost, cost_to_remove_all)<<endl;
    
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
