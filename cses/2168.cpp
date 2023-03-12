#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define INF 1e9

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int n;
  cin>>n;

  vector<pair<int,pair<int,int>>> input_pair;

  for(int i=0;i<n;i++) {
    int a,b;
    cin>>a>>b;

    input_pair.push_back(make_pair(i,make_pair(a,b)));    
  }

  vector<int> contains(n);
  vector<int> contained(n);

  sort(input_pair.begin(), input_pair.end(), [](pair<int,pair<int,int>> i, pair<int,pair<int,int>> j) {
    if (i.second.first != j.second.first) {
      return i.second.first < j.second.first;
    } else {
      return i.second.second > j.second.second;
    }
  });

  int max_end = input_pair[0].second.second;

  for(int i=1;i<n;i++) {
    if (max_end >= input_pair[i].second.second) {
      contained[input_pair[i].first] = 1;
    } else {
      max_end = input_pair[i].second.second;      
    }
  }

  reverse(input_pair.begin(), input_pair.end());

  int min_end = input_pair[0].second.second;  

  for(int i=1;i<n;i++) {
    if(input_pair[i].second.second >= min_end) {
      contains[input_pair[i].first] = 1;
    } else {
      min_end = input_pair[i].second.second;          
    }
  }

  print_vec(contains);
  print_vec(contained);  
  // cout<<"done"<<endl;
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
