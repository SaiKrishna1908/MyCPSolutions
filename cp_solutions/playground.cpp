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
  int n = 10;


  vector<int> a(n+1);

  for(int i=1;i<=n;i++) {
    a[i] = 2 * i + 19;
  }

  a[6] = 33;
  a[8] = 33;  

  print_vec(a);

  // For lower_bound if we pass a value the returned elements will not be less than val
  // ie element[i] >= val

  auto lower_33 = lower_bound(a.begin(), a.end(), 33) - a.begin();  


  // For upper_bound unlike lowerbound only elements strightly greater than val are returned
  // ie element[i] > val
  auto upper_33 = upper_bound(a.begin(), a.end() ,33) - a.begin();
  cout<<"Lower is "<<lower_33<<endl;
  cout<<"Upper is "<<upper_33<<endl;
}