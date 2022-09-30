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
    int n,m,sx,sy,d;

    // 2 3 1 3 0 
    cin>>n>>m>>sx>>sy>>d;

    bool is_left_blocked = (sy - d <= 1);
    bool is_right_blocked = (sy + d >= m);
    bool is_top_blocked = (sx-d <= 1);
    bool is_bot_blocked = (sx+d >= n);

    if (is_left_blocked && is_top_blocked) {
      cout<<-1<<endl;
      continue;
    } else if (is_right_blocked && is_bot_blocked) {
      cout<<-1<<endl;
      continue;
    } else if (is_right_blocked && is_left_blocked) {
      cout<<-1<<endl;
      continue;
    } else if (is_top_blocked && is_bot_blocked) {
      cout<<-1<<endl;
      continue;
    } else {
      cout<<(n+m-2)<<endl;
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
