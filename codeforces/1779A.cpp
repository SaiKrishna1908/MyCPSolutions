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

    string s;

    cin>>s;

    bool contains_r = false;
    bool contains_l = false;    

    for(int i=0;i<n;i++) {
      if (s[i] == 'L') {
        contains_l = true;
      } else if (s[i] == 'R') {
        contains_r = true;
      }
    }

    if (contains_l && contains_r) {
      if (s[0] == 'R' && s[n-1] == 'L') {
        cout<<0<<endl;        
      } else {
        int min_count = 0;
        for(int i=0;i<n;i++) {
          if (s[i] == 'R') {
            min_count = i;
            break;
          }
        }
        // for(int i=n-1;i>=0;i--) {
        //   if (s[i] == 'L') {
        //     min_count = max(min_count, (n-1 - i));
        //   }
        // }
        cout<<min_count<<endl;
      }
    } else {
      cout<<-1<<endl;
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
