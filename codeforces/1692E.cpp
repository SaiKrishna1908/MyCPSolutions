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
    int n, k;

    cin>>n>>k;
    
    vector<int> vc(n);
    vector<int> prefix_sum(n);

    vc[0] = 0;

    int sum = 0;

    for(int i=0;i<n;i++) {
      cin>>vc[i];

      sum+=vc[i];           
      prefix_sum[i] = sum;       
    }

    // print_vec(prefix_sum);

    int min_r = INT_MAX;

    for(int l=0;l<n;l++) {
      int low = l;
      int high = n-1;
      int pos = -1;      

      while(low <= high) {
        int mid = low + (high - low)/2;

        int psum = prefix_sum[mid] - (l ? prefix_sum[l-1] :0);

        if (psum > k) {          
          high = mid-1;
        } else if (psum < k) {          
          low = mid+1;
        } else if (psum == k) {
          pos = mid;
          low = mid+1;
        }
      }       

      if (pos != -1)      
        min_r = min(min_r, n - (pos-l+1));
                              
    }    

    if (min_r == INT_MAX)  {
      cout<<-1<<endl;
    } else {
      cout<<min_r<<endl;
    }    
    // sort(dq.begin(), dq.end(), greater<>());      
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
