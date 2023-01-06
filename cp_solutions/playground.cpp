#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

int main () {
  vector<int> v(5);
  
  v[0]=1;
  v[1]=3;
  v[2]=4;
  v[3]=9;
  v[4]=12;


  int neg_idx = lower_bound(v.begin(), v.end() , -1) - v.begin();

  cout<<neg_idx<<endl;

  int high_idx = lower_bound(v.begin(), v.end() , 20) - v.begin();

  cout<<high_idx<<endl;
}