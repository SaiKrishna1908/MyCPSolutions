#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

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

    vector<ll> v(n);
    vector<ll> primes_b(n);

    for(int i=0;i<n;i++) {
      cin>>v[i];
    }

    sort(v.begin(), v.end());

    bool is_distinct = true;

    for(int i=0;i<n-1;i++) {
      if (v[i]  == v[i+1]) {        
        is_distinct = false;
      }
    }

    if (!is_distinct) {
      cout<<"NO"<<endl;
      continue;
    }

    bool is_crt = true;

    for(int mod = 2;mod <= n/2; mod++) {
      fill(primes_b.begin(), primes_b.begin() + mod, 0);

      for(int i=0;i<n;i++) {
        primes_b[v[i]%mod]++;
      }

      if (*min_element(primes_b.begin(), primes_b.begin() + mod) >= 2)  {
        is_crt = false;
        break; 
      }
    }

    if (is_crt) {
      cout<<"Yes"<<endl;
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
