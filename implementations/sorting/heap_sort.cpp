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

int left(int i) {
  return 2*i;
}

int right(int i) {
  return 2*i+1;
}

void heap_sort(vector<int>& v, int  i) {
  int leftIdx = left(i);
  int rightIdx = right(i);

  int largest = i;

  if (leftIdx < v.size() && v[largest] < v[leftIdx]) {
      largest = leftIdx;
  }

  if (rightIdx < v.size() && v[largest] < v[rightIdx]) {
    largest = rightIdx;
  }

  if (largest != i) {
    int temp = v[i];
    v[i] = v[largest];
    v[largest] = temp;

    heap_sort(v, largest);
  }
}

void run() {
  int n;
  cin>>n;

  vector<int> v(n+1);

  for(int i=1;i<=n;i++) {
    cin>>v[i];
  }

  /*
    It's enough to run heap_sort from 1 to n/2, because after n/2 all are leaf nodes.
  */
  for(int i=n/2;i>=1;i--) {
    heap_sort(v,i);  
  }

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
