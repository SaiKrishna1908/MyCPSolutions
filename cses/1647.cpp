#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

int mod = 1e9 + 7;

struct segtree
{

  int n;

  vector<int> t;

  segtree(int N)
  {

    n = N + 1;
    t.assign(4 * n + 1, 0);
  }

  /*
    v is the current vertex
    l is the starting range of a covered by vertex v
    r is the ending range of a coverted by vertex v
  */
  void build(int a[], int v, int l, int r)
  {

    if (l == r)
    {
      t[v] = a[l];
    }

    else
    {
      int mid = (l + r) / 2;
      build(a, v * 2, l, mid);
      build(a, v * 2 + 1, mid + 1, r);

      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }

  /*
    v is the current vertex
    tl is the lower range converted by vertex v
    tr is the higher range converted by vertex v
    l is the lower range of the query
    r is the higher range of the the query
  */
  int sum(int v, int tl, int tr, int l, int r)
  {

    if (l > r)
    {
      return 0;
    }

    if (l == tr && r == tr)
    {
      return t[v];
    }

    int tm = (tl + tr) / 2;

    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
  }

  /*
    v is the vertex
    tl is the lower range of the vertex
    tr is the higher range of the vertex
    pos is the position of the element to change
    new_val is the new value to be updated at a[pos]
  */
  void update(int v, int tl, int tr, int pos, int new_val)
  {

    if (tl == tr)
    {
      t[v] = new_val;
    }

    else
    {

      int tm = (tl + tr) / 2;

      if (pos <= tm)
      {
        update(v * 2, tl, tm, pos, new_val);
      }
      else
      {
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      }

      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
};

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
  int n, q;

  cin>>n;

  int a[n+1];

  for (int i = 1; i <= n; i++)
  {
    cin>>a[i];
  }

  auto s = segtree(n);
  s.build(a, 1, 1, n);

  int sum_query = s.sum(1, 1, n, 1, 4);

  cout<<sum_query<<endl;
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
