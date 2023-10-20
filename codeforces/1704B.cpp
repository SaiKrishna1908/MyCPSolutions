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

/*
    This problem is based on finding intersection of interval's    

    intersection between (ai, bi) (aj, bj) (ak, bk) can be found by following technique


    left_intersection = max(ai, aj)
    right_intersection = min(bi, bj)

    (left_intersection, right_intersection) -> new interval which 


    left_intersection = max(ak, left_intersection)
    right_intersection = min(bk, right_intersection)

    How do we know if there is no intersection ?

    -> At any point if left_intersection > right_intersection, there is not intersection
*/
void run() {
  int t;
  cin>>t;

  while(t-->0) {
    int n,x;

    cin>>n>>x;

    vector<int> a(n);

    for(int i=0;i<n;i++) {
      cin>>a[i];
    }

    int left_intersection = a[0]- x;
    int right_intersection = a[0] + x;

    int count = 0;

    for(int i=1;i<n;i++) {
      int current_max_left = a[i] - x;
      int current_max_right = a[i] + x;

      left_intersection = max (left_intersection , current_max_left);
      right_intersection = min (right_intersection, current_max_right);

      if (left_intersection > right_intersection) {
        count++;
        left_intersection = current_max_left;
        right_intersection = current_max_right;
      }
    }

    cout<<count<<endl;
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
