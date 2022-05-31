#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  int t;

  cin>>t;
 
  while(t-->0) {
    int n;

    cin>>n;

    vector<int> arr(n);

    int ones_flag = 0;

    for(int i=0;i<n;i++) {
      cin>>arr[i];
      ones_flag+=arr[i];
    }

    if (ones_flag == n) {
      if (n%2) {
	cout<<"First"<<endl;
	continue;
      }
      cout<<"Second"<<endl;
      continue;
    }

    int chance = 0;

    bool brk = false;

    for(int i=0;i<n;i++) {
      if (brk) {
	break;
      }
      if (arr[i] > 1) {
	if(chance) {
	  cout<<"Second"<<endl;
	} else {
	  cout<<"First"<<endl;	
	}
	brk=true;
      }
      chance ^= 1;
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
