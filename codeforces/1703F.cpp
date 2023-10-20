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


void run() {
  int t;

  cin>>t;
  while(t-->0) {
    int n;

    cin>>n;

    vector<int> input(n+1);


    for(int i=1;i<=n;i++) {
      cin>>input[i];
    }

    vector<pair<int,int>> valid_num;


    for(int i=1;i<=n;i++) {
      if (input[i] < i) {
        valid_num.push_back(make_pair(i, input[i]));
      }
    }

    ll count = 0;


    sort(valid_num.begin(), valid_num.end(), [] (pair<int,int> i, pair<int,int> j) { return i.second < j.second;});

    for(int i=0;i<valid_num.size();i++) {
      auto p = valid_num[i];

      int search_value = p.first;

      // binary search for p

      int low = i;
      int high  = valid_num.size() - 1;

      int mid = 0;

      while(low <= high) {
        mid = low+(high - low)/2;

        if (valid_num[mid].second < search_value) {
          low = mid + 1;
        } else if (valid_num[mid].second > search_value) {
          high = mid - 1;
        } else {
          break;
        }
      }

      if (valid_num[mid].second > search_value) {
        count += (valid_num.size() - mid);
      } else {
        while(mid < valid_num.size() && valid_num[mid].second <= search_value) {
          mid++;
        }
      
        count += (valid_num.size() - mid);
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
