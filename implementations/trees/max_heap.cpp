/*
    Max heap implementation

*/


#include <bits/stdc++.h>

using namespace std;

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

int main() {
    vector<int> heap;

    heap.push_back(40); // 0
    heap.push_back(50); // 1
    heap.push_back(10); // 2
    heap.push_back(15); // 3
    heap.push_back(50); // 4
    heap.push_back(40); // 5
    heap.push_back(100); //6
    heap.push_back(120);
    heap.push_back(30);
    
    // Last non-leaf node
    int last_non_leaf_node = floor(heap.size()/2) - 1;
    for(int i=last_non_leaf_node;i>=0;i--) {
        __heapify(heap, i);
    }

    print_vec(heap);
    
    removeMax(heap);
    cout<<"removed max"<<endl;

    print_vec(heap);

    insert(heap, 199);
    insert(heap, 45);
    cout<<"inserted value"<<endl;

    print_vec(heap);
    return 0;
}


