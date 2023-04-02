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

bool isValid(int a, int b, int c, int d) {
  if (a == b || a==c || a==d || b==c || b==d || c==d) {
    return false;
  } 

  return true;
}

void run()
{
  ll n, x;

  cin >> n >> x;

  vector<pair<ll, int>> v(n);

  for (int i = 0; i < n; i++)
  {
    ll num;
    cin >> num;
    v[i] = make_pair(num, i + 1);
  }

  sort(v.begin(), v.end());

  bool is_possible = false;

  vector<int> ans(4);

  map<ll, pair<int,int>> hmap; 
  
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v.size(); j++)
    {
      if (i == j) {
        continue;
      }
      ll sum = v[i].first + v[j].first;

      ll needed = x - sum;

      if (hmap.count(needed) ) {
        if (isValid(v[i].second,v[j].second,hmap[needed].first, hmap[needed].second)) {
          cout<<v[i].second<<" "<<v[j].second<<" "<<hmap[needed].first<<" "<<hmap[needed].second<<endl; 
          is_possible= true;
          break;
        }       
      }
      
      hmap.insert(make_pair(sum, make_pair(v[i].second, v[j].second)));
    }

    if (is_possible) {
        break;
    }
  }

  if (!is_possible) {
    cout<<"IMPOSSIBLE"<<endl;
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
