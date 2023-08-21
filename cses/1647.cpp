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

  void build(int a[], int v, int l, int r)
  {

    if (l == r)
    {
      a[v] = a[l];
    }

    else
    {
      int mid = (l + r) / 2;
      build(a, v * 2, l, mid);
      build(a, v * 2 + 1, mid + 1, r);

      a[v] = a[v * 2] + a[v * 2 + 1];
    }
  }

  int sum(int v, int l, int r, int tl, int tr)
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

    return sum(v, l, min(r, tm), tl, tm) + sum(v, max(l, tm + 1), r, tm + 1, tr);
  }

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

  vector<int> a(n);

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      cin >> a[i];
    }
    else
    {
      cin >> a[i];

      a[i] = min(a[i], a[i - 1]);
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
