#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

void solve(vector<int> &vec, int min_value, vector<pair<int,int>> &sol) {
  assert(min_value > 1);
  int n = vec.size();  
  int operation_count = 0;

  while (true) {
    int current_min = INT_MAX;
    int current_max = INT_MIN;
    int current_min_idx = -1;
    int current_max_idx = -1;

    for(int i=0;i<n;i++) {
      if (current_min > vec[i]) {
        current_min_idx = i;
        current_min = vec[i];
      }

      if (current_max < vec[i]) {
        current_max_idx = i;
        current_max = vec[i];
      }      
    }

    if (current_max == current_min) {
      break;
    }

    sol.push_back(make_pair(current_min_idx+1, current_max_idx+1));

    operation_count++;
    vec[current_max_idx] = ceil((double) current_max/current_min);    
  }

  cout<<operation_count<<endl;
}


void run() {
  int t;
  cin>>t;

  while(t-->0) {
    int n;
    cin>>n;

    vector<int> v(n);

    bool isPossible = true;
    int min_value = INT_MAX;
    int count_one = 0;

    for(int i=0;i<n;i++) {
      cin>>v[i];
      if (v[i] == 1) {
        count_one++;
        isPossible = false;
      }

      min_value = min(min_value, v[i]);       
    }

    if (count_one == v.size()) {
      cout<<0<<endl;
      continue;
    }
    else if (!isPossible) {
      cout<<-1<<endl;
    } else {
      vector<pair<int,int>> solution;
      // sort(all(v));
      solve(v, min_value, solution);

      for(int i=0;i<solution.size();i++) {
        cout<<solution[i].second<<" "<<solution[i].first<<endl;
      }
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
