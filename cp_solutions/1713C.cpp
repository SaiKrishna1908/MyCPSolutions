#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


int arr[100007];

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

void solve(int end_index) {

  if (end_index < 0) {
    return;
  }

  int smallest_possible_square = sqrt(2 * end_index);
  smallest_possible_square = pow(smallest_possible_square, 2);
  int start_index =  smallest_possible_square - end_index ;
  solve(start_index - 1);

  while(start_index <= end_index) {
    arr[start_index] = end_index;
    arr[end_index] = start_index;

    start_index++;
    end_index--;
  }
}


void run() {
  int t;

  cin>>t;

  while(t-->0) {

    int n;
    cin>>n;
    solve(n-1);        

    for(int i=0;i<n;i++) {
      cout<<arr[i]<<" ";
    }

    cout<<endl;
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
