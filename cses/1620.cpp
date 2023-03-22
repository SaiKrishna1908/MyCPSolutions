#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e18
#define MAXN 2e5+7

int t;

vector<int> v(MAXN);

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

ll compute(ll num, int n) {
    ll sum = 0;

    for(int i=0;i<n;i++) {
        sum += num / (v[i]);

        if (sum >= t) {
            break;
        }
    }    

    return sum;
}


void run() {
  int n;

  cin>>n>>t;

  

  for(int i=0;i<n;i++) {
    cin>>v[i];
  }

  ll low = 0;
  ll high = INF;
  ll ans;

  while(low <= high) {
    ll mid = low + (high - low)/2;

    ll sum = compute(mid, n);

    if(sum >= t) {
        ans = mid;
        high = mid-1;
    } else if (sum < t) {
        low = mid+1;
    }
  }

  cout<<ans<<endl;
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
