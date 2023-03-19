#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7
int MAXN = 200007;

map<int, int> co_map;

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

struct BIT
{
  vector<ll> v;

  BIT()
  {
    v = vector<ll>(MAXN);
  }

  void update(int element, int position, int max)
  {
    while (position <= max)
    {
      v[position] += element;
      position += (position & (-position));
    }
  }

  int query(int position)
  {
    int sum = 0;
    while (position > 0)
    {
      sum += v[position];
      position -= (position & (-position));
    }
    return sum;
  }

  int query_range(int left, int right)
  {
    return query(right) - query(left - 1);
  }
};

void run()
{
  int n;
  cin >> n;

  vector<pair<int, pair<int, int>>> input_pair(n);
  set<int> y_cor;

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;

    input_pair[i] = make_pair(i, make_pair(a, b));
  }

  sort(input_pair.begin(), input_pair.end(), [](pair<int, pair<int, int>> i, pair<int, pair<int, int>> j)
       {
    if (i.second.first != j.second.first) {
      return i.second.first < j.second.first;
    } else {
      return i.second.second > j.second.second;
    } });

  for (int i = 0; i < n; i++)
  {
    y_cor.insert(input_pair[i].second.second);
  }
  
  int cnt = 0;
  for(auto b: y_cor) {
    co_map[b] = ++cnt;
  }

  auto bit = BIT();

  vector<ll> contained(n);
  vector<ll> contains(n);

  bit.update(1, co_map[input_pair[n-1].second.second], cnt);

  for (int i = n-2; i >= 0; i--)
  {
    contains[input_pair[i].first] = bit.query(co_map[input_pair[i].second.second]);
    bit.update(1, co_map[input_pair[i].second.second], cnt);     
  }

  auto bit2 = BIT();

  // bit2.update(1, 1, n);
  // bit2.update(-1, co_map[input_pair[0].second.second], n);

  for(int i=0;i<n;i++) {
    int ans = bit2.query(co_map[input_pair[i].second.second]);
    bit2.update(1,1,n);
    bit2.update(-1,co_map[input_pair[i].second.second] +1, n);
    contained[input_pair[i].first] = ans;
  }

  for (int i = 0; i < contains.size(); i++)
  {
    cout << contains[i] << " ";
  }

  cout<<endl;
  for (int i = 0; i < contains.size(); i++)
  {
    cout << contained[i] << " ";
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
