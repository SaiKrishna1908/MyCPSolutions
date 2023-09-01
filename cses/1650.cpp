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

struct segtree
{

  int n;

  vector<ll> t;

  segtree(int N)
  {
    n = N;
    t.assign(4 * n + 1, 0);
  }
  void build(ll a[], int currentVertex, int l, int r)
  {
    if (l == r)
    {
      // this is a leaf node
      t[currentVertex] = a[l];
    }
    else
    {

      auto mid = l + (r - l) / 2;

      build(a, currentVertex * 2, l, mid);
      build(a, currentVertex * 2 + 1, mid + 1, r);

      t[currentVertex] = t[currentVertex * 2] ^ t[currentVertex * 2 + 1];      
    }
  }

  ll query_xor(int currentVertex, int segmentLow, int segmentHigh, int ql, int qr) {
    if (segmentLow > segmentHigh || ql > qr) {
      return 0;
    } else if (segmentLow == ql && segmentHigh == qr) {
      return t[currentVertex];
    } else {
      int mid = segmentLow + (segmentHigh -  segmentLow)/2;
      /*
        the min() and max() are make the call useless if the query range does not lie in next segment.
        This is caught by the first statement in the query_xor.
      */ 

      return query_xor(currentVertex * 2, segmentLow, mid, ql, min(qr, mid)) ^ query_xor(currentVertex * 2 + 1, mid+1, segmentHigh, max(ql, mid+1), qr);
    }   
  }
};

void run()
{
  int n,q;
  cin>>n>>q;

  ll a[n+1];

  for(int i=1;i<=n;i++) {
    cin>>a[i];    
  }

  auto st = segtree(n);

  st.build(a, 1, 1, n);

  for(int i=0;i<q;i++) {
    int x,y;
    cin>>x>>y;

    cout<<(st.query_xor(1, 1, n, x, y))<<endl;;
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
