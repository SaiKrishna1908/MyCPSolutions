#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);
struct debug {
    
    ~debug() { cerr << endl; }
    template < class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return * this; }
    template < class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return * this << range(begin(i), end(i)); }
    template < class c, class b > debug & operator <<(pair < b, c > d) {
        return * this << "(" << d.first << ", " << d.second << ")";
    }
    template < class c > debug & operator <<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return * this << "]";
    }
    
};

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

    void insert(int value) {
        if (root == NULL) {            
            root = newNode(value);
            return;
        } else {
            auto nodeToInsert = newNode(value);
            auto temp = root;                        
            
            while(temp->left != NULL || temp->right != NULL) {                
                if (temp->key > value) {
                    if (temp->left == NULL) {
                        break;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        break;
                    }
                    temp = temp->right;
                }                                
            }

            if (temp->key > value) {
                temp->left = nodeToInsert;
            } else {
                temp->right = nodeToInsert;
            }
        }
    }

    void recursiveInorderWalk(Node *node) {
        if (node == nullptr) {
            return;
        } 

        recursiveInorderWalk(node->left);
        cout<<(node->key)<<" ";
        recursiveInorderWalk(node->right);
    }

    void printTree(Node *node, string prefix, bool isLeft) {
        if (node != nullptr) {
            cout<<prefix;
            cout<<(isLeft ? "|--":"|__");

            cout<<node->key<<endl;

            printTree(node->left, prefix + (isLeft ? "|   " : "    "), true);
            printTree(node->right, prefix + (isLeft ? "|   " : "    "), false);

        }
    }
};

void run() {
  auto tree = bst(13);
  tree.insert(10);
  tree.insert(9);
  tree.insert(11);
  tree.insert(15);
  tree.insert(12);

  tree.printTree(tree.root,"", false);

  tree.recursiveInorderWalk(tree.root);
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
