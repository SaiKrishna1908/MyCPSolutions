#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
  int n,a,b;

  cin>>n>>a>>b;

  int left_count =1, right_count=1, middle_count=0;

  for(int i=1;i<=n;i++) {

    if(i == a || i ==b) {
      continue;
    }

    if(i>a && i<b) {
      middle_count++;
    } else if (i>a) {
      left_count++;
    } else if(i<b) {
      right_count++;
    }
  }

  int left_needed = n/2-left_count;
  int right_needed = n/2-right_count;

  if(left_needed < 0 || right_needed <0) {
    cout<<-1<<endl;
    return;
  }

  if(a>b) {
    if(a-b>1) {
      cout<<-1<<endl;
      return;
    }
    else {
      for(int i=a;i<=n;i++) {
        cout<<i<<" ";
      }

      for(int i=b;i>=1;i--) {
        cout<<i<<" ";
      }

      cout<<endl;
      return;
    }
  }


  // left most elements
  for(int i=b+1;i<=n;i++) {
    cout<<i<<" ";
  }

  for(int i=a;i<=a+(n/2-a);i++) {
    cout<<i<<" ";
  }

  for(int i=a+(n/2-a)+1;i<=b;i++) {
    cout<<i<<" ";
  }
  for(int i=1;i<a;i++) {
    cout<<i<<" ";
  }
  cout<<endl;

}

int main() {

    // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  int t;

  cin>>t;

  while(t-->0) {
    run();
  }
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
