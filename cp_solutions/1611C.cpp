#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  int n;
  cin>>n;

  vector<int> a(n);

  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  // From the problem we can say that highest element can be either in first place 
  // or last place

  if(a[0] != n && a[n-1] != n) {
    cout<<-1<<endl;
    return;
  }

  else {    
    /*
    
     Why this works ?

     if input is [2, 1, 5 , 3, 4, 6]

     answer = [6, 4, 3, 5, 1 ,2]

     steps => [] => [2] => [2, 1] => [2, 1, 5] => [2, 1, 5, 3] => [2, 1, 5, 3, 4] => [6,2,1,5,3,4]
          

    */
    for(int i=n-1;i>=0;i--) {
      cout<<a[i]<<" ";
    }
  }
  cout<<endl;
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  // auto start = high_resolution_clock::now();
  
  int t;
  cin>>t;

  while(t-->0) {
    run();
  }
  
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
