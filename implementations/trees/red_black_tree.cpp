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

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* parent;
    Node* left;
    Node* right;

    Node(int data) : data(data), color(RED), parent(nullptr), left(nullptr), right(nullptr){}
};

class RedBlackTree {
    private:
        Node *root;
    
        void leftRotate(Node* x);
        void rightRotate(Node* x);
        void insertFixup(Node *z);
        void printTree(Node* node, int indet);
    
    public:
        RedBlackTree(): root(nullptr) {}

        void insert(int data);
        void print();
};

/*
            x                              y
           / \           L R              / \
         a    y         =====>           x   c
             / \                        / \
            b   c                      a   b
*/
void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->right;    

    // Check if right child exists for x, if it does make these changes
    if (y != nullptr) {
        x->right = y->left;
        y->left->parent = x;
    }
    
    y->parent = x->parent;

    // if x the root, then after left rotate y will become root
    if (x->parent == nullptr) {
        root = y;
    } 
    // check if x is left child or right child of the parent and exchange
    else if (x = x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    // switch x and y
    y->left = x;

    // make parent of x -> y
    x->parent = y;
}

/*
            x                                   y
           / \              R. R               / \
          y   c          =========>           a   x
         / \                                     / \
        a   b                                   b   c
*/

void RedBlackTree::rightRotate(Node *x) {
    Node* y = x->left;
    
    if (y != nullptr) {
        x->left = y->right;        
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
        root = y;
    }

    if (x->parent->left == x) {
        x->parent->left = y;
    } else  {
        x->parent->right = y;
    }    

    y->right = x;

    x->parent = y;
}


void RedBlackTree::insert(int data) {
    Node* z = new Node(data);
    Node* y = nullptr;
    Node* x = root;

    while (x!=nullptr) {
        y = x;

        if (x->data < z->data) {
            x = x->right;
        } else {
            x = x->left;
        }
    }

    z->parent = y;

    if (y==nullptr) {
        root = z;
    } else if (z->data > y->data) {
        y->right = z;
    } else {
        y->left = z;
    }

    insertFixup(z);
}

void RedBlackTree::print() {
    printTree(root, 0);
}

void RedBlackTree::printTree(Node* node, int indent) {
    if (node == nullptr) {
        return;
    }

    if (node->right) {
        printTree(node->right, indent+4);
    }

    for(int i=0;i<indent;i++) {
        cout<<" ";
    }

    cout<<node->data<<" ";

    if (node->color = RED) {
        cout<<"R"<<endl;
    } else {
        cout<<"B"<<endl;
    }


    if (node-> left) {
        printTree(node->left, indent + 4);
    }
}

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
