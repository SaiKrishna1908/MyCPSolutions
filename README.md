# Bits:

## Manipulating Bits

    i << 1 (multipy i with 2, ie i*2 )

    i<<n (multiply i with 2^n) [ Shift bits leftside

    i << 1 | 1 (multiply i with 2 and add  1, ie 2*i+1)

    i >> 1 (divide i with 2;  ie i/2)

    i >> n (divide i with 2^n) [ Shift bits rightside ]

    For binary trees children of a parent i are a[i], a[i^1]

    Square of a number i : 1 << i

## Get MOST SIGNIFICANT BIT

    int rqmsb = rq >> (sizeof(rq)*8 - 1) & 1;

    (or)

    int msb(int n) {

        if(n ==0 ){
        	 return 0;
        }

        n/=2;
        msb=0;

        while(n!=0) {
        	n/=2;
    	msb+=1;
        }

        return msb;

    }

## Segment Tree 

Time complexity: 
    build: O(n)
    query: O(log n)
    update: O(log n)

```
struct segtree
{
 
  int n;
 
  vector<ll> t;
 
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
  void build(ll a[], int v, int l, int r)
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
      // For min query comment above line and uncomment below line
      // t[v] = min (t[v * 2], t[v * 2 + 1]);
    }
  }

  /*
    v is the current vertex
    tl is array start index 
    tr is array end index
    l is the lower range of the query
    r is the higher range of the query
  */
  int query_min(int v, int tl, int tr, int l , int r) {
 
    if (l > r || tl > tr) {
      return MAX;
    }
 
    if (l == tl && r == tr) {
      return t[v];
    }
 
    int tm = (tl + tr) / 2;
 
    return min(query_min(v*2, tl, tm, l, min(r, tm)),
            query_min(v*2+1, tm+1, tr, max(l, tm+1), r));
  }
 
  /*
    v is the current vertex
    tl is the lower range converted by vertex v
    tr is the higher range converted by vertex v
    l is the lower range of the query
    r is the higher range of the the query
  */
  ll sum(int v, int tl, int tr, int l, int r)
  {
 
    if (l > r)
    {
      return 0;
    }
 
    if (l == tl && r == tr)
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

usage:

int n;
cin>>n;
int a[n+1];

read(a);

auto s = segtree(n);
s.build(a,1,1,n)
```

## Binary Index Tree

```
  struct BIT {

  int n;
  vector<int> bit;

  BIT(int N) {

      n = N;
      bit.assign(N+1,0);

  }

  void update(int i, int v) {
  while( i<=n ) {

        bit[i] = (bit[i] + v)%mod;

        i += i & (-i);
      }

  }

      int query(int i) {

        int res = 0;

        while (i>0) {

      res = (res+bit[i])%mod;

      i-=i & (-i);
        }

        return res;
      }

  };
```

## Modular Exponentiation

(https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/modular-exponentiation)

```
  int modularExponentiation(int x,int n,int M)
  {
  if(n==0)
    return 1;
  else if(n%2 == 0) //n is even
    return modularExponentiation((x*x)%M,n/2,M);
  else //n is odd
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

  }
```

## Graph Properties

- If m<n−1, the graph can't be connected, so the answer should be No.

- If m>n(n−1)2, the graph must contain multiedges, so the answer should be No.

- If m=n(n−1)2, the graph must be a complete graph. The diameter of the graph is 1. If k>2 the answer is YES, otherwise the answer is NO.

- If n=1, the graph has only one node, and its diameter is 0. If k>1 the answer is YES, otherwise the answer is NO.

- If m=n−1, the graph must be a tree, the diameter of the tree is at least 2 when it comes to each node has an edge with node 1.
- If m>n−1 and m<n(n−1)2, we can add edges on the current tree and the diameter wouldn't be more than 2. Since the graph is not complete graph, the diameter is more than 1, the diameter is just 2. If k>3 the answer is YES, otherwise the answer is NO.

## Fast Modular Exponentiation

How to calcuate A^B mod C quickly if B is a power of 2

```
  int mexpo(int A, int B, int M ) {

    if (A==0) {

        return 0;

    }

    if (B==0) {
    return 1;
    }

    int y;

    if(B%2 == 0) {

        y = mexpo(A,B/2,M);
        y = (y*y)%c;

  }
    else {
    y = A % C;
    y = (y\* mexpo(A,B-1)%M)%M;
  }

    return (int)((y+M) %M);
  }
```

## Given an array of numbers find different sums that are possible

```
  bitset b<maxsum>;
  b[0] =1;
  for elem in array:
  b = b | (b<<elem)
```

# Utils

## Create a Comparator and use it with a set

```
auto cmp = [] (pair<int,int> const &x, pair<int,int> const &y) {
if (x.second != y.second)
return x.second > y.second;

    return x.first > y.first;

};
set<pii, decltype(cmp)> a(cmp);
```

## Sorting Vector using Lambas

```
vints[i].sort([&words](int i, int j) { return words[i] < words[j]; });

(or)

vector<pair<char,int>> mapl(n);
sort(mapl.begin(),mapl.end(),[](auto i,auto j) { return i.first < j.first;});
```

## Fill 2d arrays with -1

```
int dp[n][m];

fill(&dp[0][0], &dp[0][0]+sizeof(dp), -1);
```



## Compile code with debug 

```
g++ -std=c++17 -Wshadow -Wall -o ./a .\cp_solutions\playground.cpp  -D_GLIBCXX_DEBUG -g
```