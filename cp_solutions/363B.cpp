#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  int n,k;

  cin>>n>>k;

  vector<int> arr(n);

  int curr_sum = 0;
  int min_sum = 0;
  int min_index = 0;

  for(int i=0;i<n;i++) {
    cin>>arr[i];
  }

  for(int i=0;i<k;i++) {
    curr_sum+=arr[i];
  }

  min_sum = curr_sum;

  for(int del_num=0,add_num=k;add_num<n;del_num++,add_num++) {
      curr_sum -= arr[del_num];
      curr_sum += arr[add_num];      

      if(curr_sum < min_sum) {
        min_sum = curr_sum;
        min_index = del_num+1;
      }
  }

  cout<<min_index+1<<endl;
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
