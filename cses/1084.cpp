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

bool is_between(int *min, int *max, int *val) {
    if (*val >= *min && *val<=*max) {
        return true;
    }

    return false;
}


void run() {
  int n,m,k;

  cin>>n>>m>>k;

  vector<int> req_size(n);
  vector<int> home_size(m);

  for(int i=0;i<n;i++) {
    cin>>req_size[i];
  }

  for(int i=0;i<m;i++) {
    cin>>home_size[i];
  }

  sort(req_size.begin(), req_size.end());
  sort(home_size.begin(), home_size.end());


  int count = 0;

  for(int i=0;i<n;i++) {
    int min_size = req_size[i] - k;
    int max_size = req_size[i] + k;

    int idx = lower_bound(home_size.begin(), home_size.end(), min_size) - home_size.begin();

    if (is_between(&min_size, &max_size, &home_size[idx])) {
        home_size[idx] = 0;
        count++;
    }    
  }

  cout<<count<<endl;
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
