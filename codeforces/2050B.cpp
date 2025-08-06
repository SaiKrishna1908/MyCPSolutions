#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);
struct debug {
    
    ~debug() { cerr << endl; }
    template < class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return * this; }
    template < class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return * this << range(begin(i), end(i)); }
    template < class c, class b > debug & operator <<(pair < b, c > d) {
        return * this << "(" << d.first << ", " << d.second << ")";
    }
    template < class c > debug & operator <<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return * this << "]";
    }
    
};

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int t;
  cin>>t;

  while(t-->0) {
    int n;
    cin>>n;

    vector<ll> arr(n);

    ll sum = 0;

    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }    

    if (sum % n != 0) {
        cout<<"NO"<<endl;
        continue;
    }

    sum = sum/n;


    ll sum1=0,c1=0;
    ll sum2=0,c2=0;

    for(int i=0;i<n;i+=2) {
        sum1+=arr[i];
        c1++;
    }

    for(int j=1;j<n;j+=2) {
        sum2+=arr[j];
        c2++;
    }

    sum1/=c1;
    sum2/=c2;    

    if (sum1 == sum2 && sum1 == sum) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
  }
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
