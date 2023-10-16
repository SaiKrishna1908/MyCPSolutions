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

int partition(vector<int>& v, int p , int q) {
  int partitionElement = v[p];
  int currentLeastIdx = p;

  for(int j=currentLeastIdx+1;j<=q;j++) {
    if (v[j] <= partitionElement) {
      currentLeastIdx+=1;
      int temp = v[j];
      v[j] = v[currentLeastIdx];
      v[currentLeastIdx] = temp;
    }
  }

  int temp = v[p];
  v[p] = v[currentLeastIdx];
  v[currentLeastIdx] = temp;

  return currentLeastIdx;
}

void quickSort(vector<int>& v, int p, int q) {
  if (p < q) {
    int i = partition(v, p , q);
    quickSort(v, p, i);
    quickSort(v, i+1, q);
  }
}

void run() {
  int n;
  cin>>n;

  vector<int> v(n+1);
  for(int i=1;i<=n;i++) {
    cin>>v[i];
  }

  quickSort(v, 1, n);
  print_vec(v);
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
