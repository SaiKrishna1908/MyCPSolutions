#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN 10007

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

struct BIT
{
  vector<int> v;
  int n;


  void update(int element, int position) {
    while(position < n) {
      v[position] += element;
      position+= (position & (-position));
    }
  }

  /*
    return's from 0 to position
  */
  int query(int position) {
    int sum = 0;

    while(position > 0) {
      sum += v[position];
      position-=(position & (-position));
    }

    return sum;
  }

  int query_range(int left, int right) {
    return query(right) - query(left-1);
  }

  BIT(vector<int> &input, int capacity) {
    v = input;
    n = capacity;
  }
};


void run() {
  int n = 10;
  vector<int> v(n+1);
  auto bit = BIT(v, n); 
  
  for(int i=1;i<=n;i++) {
    bit.update(i,i);
  }

  int sum = bit.query_range(3,5);

  cout<<sum<<endl;
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
