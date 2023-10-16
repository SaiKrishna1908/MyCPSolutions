#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

int n = 6;
int arr[] = {6, 3, 2 , 5, 8, 9};


void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int p, int r) {
  int partition_element = arr[r];
  int i = p-1;

  for(int j=p;j<=r-1;j++) {
    if (arr[j] <= partition_element) {
      i++;
      swap(arr[i], arr[j]);
    }

  }

  swap(arr[i+1], arr[r]);
  return i+1;
}

void quick_sort(int p, int r) {
  if (p < r) {
    int q = partition(p,r);
    quick_sort(p, q-1);
    quick_sort(q+1, r);
  }
}

void run() {  
  quick_sort(1, n-1);

  for(int i : arr) {
    cout<<i<<" ";
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
