#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
using namespace std::chrono;
 
#define ll long long
#define all(v) v.begin(), v.end()
 
void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}
 
struct CircularQueue{
  vector<int> list;
  int ptr;
 
  void next() {
    ptr++;
    ptr%=(list.size());
  }
 
  void erase() {
    cout<<list[ptr]<<endl;    
    list.erase(list.begin() + ptr);
  }
 
  CircularQueue(vector<int> param_list, int initial_ptr) {
     list = param_list;
     ptr = initial_ptr;
  }
 
  void print() {
    cout<<(list[ptr])<<" ";
  }
};
 
void run()
{
  int n;
 
  cin>>n;
  vector<int> input(n);
 
  for (int i=0;i<n;i++)
  {
    input[i] = i+1;
  }
 
  auto circular_queue = CircularQueue(input, 0);
 
  for(int i=2;i<circular_queue.list.size();i+=2) {
    circular_queue.erase();
  }
}
 
int main()
{
 
  // cin.tie(0);
  // cin.sync_with_stdio(false);
 
  auto start = high_resolution_clock::now();
 
  run();
 
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
 
  // cout<<"time: "<<duration.count()/1e6<<endl;
}