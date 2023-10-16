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

struct Node {
    int key;
    Node* left;
    Node* right;
};

struct bst {

    Node* root = NULL;

    bst(int item) {
        root = newNode(item);
    }

    Node* newNode(int item) {
        Node* temp = new Node();
        temp->key = item;
        temp->left = temp->right - NULL;
        return temp;
    }

    Node* insert(int key) {
        if (root == NULL) {            
            root = newNode(key);
            return root;
        } else {
            auto nodeToInsert = newNode(key);
            auto temp = root;

            while(temp != NULL) {
                if (temp)
            }
        }
    }
};

void run() {
  
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
