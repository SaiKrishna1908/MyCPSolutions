#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


int a[100007];
int post[100007];
int pre[100007];

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
    int n,q;
    cin>>n>>q;
    
    a[0] = -1;

    for(int i=1;i<=n;i++) {
      cin>>a[i];

      if (a[i] > a[post[i-1]]) {
        post[i] = i;
      } else {
        post[i] = post[i-1];
      }
    }

    pre[n] = n;
    for(int i=1;i<=n;i++) {
      for(int j=i+1;j<=n;j++) {
        pre[i] = i;
        if (a[j] > a[i]) {
          pre[i] = j;
          break;
        } 
      }
    }
    

    for(int i=0;i<q;i++) {
      int pl,round;
      cin>>pl>>round;

      int right_high = -1;

      // No element is greater in left hand side
      if (post[pl] == pl) {
        if (pre[pl] != pl) {
          right_high = pre[pl];
        }
      } else {
        cout<<0<<endl;
        continue;
      }

      
      int pl_round = (pl == 1 || pl == 2) ? 1 : pl-1;

      if (round - pl_round < 0) {
        cout<<0<<endl;
        continue;
      } 
      
      // No element is greater in right hand side
      if (right_high == -1) {
        cout<<max(0, (round - pl_round + 1))<<endl;        
      } else {
        assert(right_high > 0);
        int hg_round = (right_high == 1 || right_high == 2) ? 1 : right_high - 1;
        cout<<(round >= hg_round ? hg_round - pl_round : (round - pl_round + 1))<<endl;
      }
    }
  }
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
