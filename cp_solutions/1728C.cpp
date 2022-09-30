#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void print_vec(vector<int> & arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


/*
    Use this method when we have to insert a new element in heap.
*/
void __percolate_up(int index, vector<int> & heap) {
    int parent_index = floor((index-1)/2);

    if (index <= 0) {
        return;
    } else if (heap[parent_index] < heap[index]) {
        swap(heap[parent_index], heap[index]);
        // process parent node
        __percolate_up(parent_index, heap);
    }
}

/*
    Get each index, find their children and swap if necessary.
    This follows top-down approach
*/
void __heapify(vector<int> &heap, int index) {

    int left_child = (index * 2) + 1;
    int right_child = (index * 2) + 2;

    int largest_index = index;

    if (left_child < heap.size() && heap[left_child] > heap[largest_index]) {
        largest_index = left_child;
    }

    if (right_child < heap.size() && heap[right_child] > heap[largest_index]) {
        largest_index = right_child;
    }

    // Swap needed
    if (largest_index != index) {        
        swap(heap[largest_index], heap[index]);
        // Now in largest position we have least element.
        __heapify(heap, largest_index);
    }    
}

int getMax(vector<int> & heap) {
    if (heap.size() == 0) {
        return -1;
    }    
    return heap[0];
}

int removeMax(vector<int> & heap) {
    int retVal = heap[0];

    if(heap.size() > 1) {
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        __heapify(heap, 0);        
    } else {
      heap.pop_back();
      return retVal;
    }

    return retVal;
}

void insert(vector<int> & heap, int element) {
    heap.push_back(element);
    __percolate_up(heap.size() -1, heap);
}


void run() {
  int t;

  cin>>t;

  while(t-->0) {
    int n;
    cin>>n;
    

    vector<int> a(n);
    vector<int> b(n);

    for(int i=0;i<n;i++) {
      cin>>a[i];
    }

    for(int i=0;i<n;i++) {
      cin>>b[i];
    }

   int max_non_leaf_node = floor(n/2)-1;

   for(int i = max_non_leaf_node;i>=0;i--) {
     __heapify(a, i);
     __heapify(b, i);
   }
   
    

    int count = 0;


    while(a.size() != 0 && b.size() != 0) {
      int aMax = getMax(a);
      int bMax = getMax(b);


      if (aMax == bMax) {
        removeMax(a);
        removeMax(b);
      } else if (aMax > bMax) {
        removeMax(a);
        insert(a, log10(aMax) + 1);
        count++;
      } else {
        removeMax(b);
        insert(b, log10(bMax) + 1);
        count++;
      }
    }

    cout<<count<<endl;
    
  }
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
