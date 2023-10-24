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
    Node* parent;
};

struct bst {

    Node* root = NULL;

    bst(int item) {
        root = newNode(item);
    }

    Node* newNode(int item) {
        Node* temp = new Node();
        temp->key = item;
        temp->left = temp->right = temp->parent = NULL;        
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
                nodeToInsert->parent = temp;
            } else {
                temp->right = nodeToInsert;
                nodeToInsert->parent = temp;
            }
        }
    }

    void printParentPath(Node* node) {
        if (node->parent == nullptr) {
            cout<<node->key;
            return;
        }

        cout<<node->key<<"->";
        printParentPath(node->parent);
    }

    /*
        recusive procedure to inorder walk a binary search tree
    */
    void recursiveInorderWalk(Node *node) {
        if (node == nullptr) {
            return;
        } 

        recursiveInorderWalk(node->left);
        cout<<(node->key)<<" ";
        recursiveInorderWalk(node->right);
    }

    /*
        If a max exists then it will be in rightmost leaf of the subtree/tree
    */
    Node* findMax(Node* node) {
        if (node->right != nullptr) {
            return findMax(node->right);
        }
        return node;
    }
    
    /*
        If a min exists then it will be in leftmost leaf of the subtree/tree
    */

   Node* findMin(Node* node) {
        if(node->left != nullptr) {
            return findMin(node->left);
        }
        return node;
   }

    /*
        Smallest key that is larger than x
    */
    Node* findSuccessor(Node* node) {
        if (node->right != nullptr) {
            return findMin(node->right);
        }        

        Node* parent = node->parent;
        while(parent != nullptr && parent->right == node) {
            node = parent;
            parent = node->parent;
        }
        
        return parent;
    }

    /*
        Largest key that is smaller than x
    */
    Node* findPredessor(Node* node) {
        if (node->left != nullptr) {
            return findMax(node->left);
        } 

        auto parent = node->parent;

        while(parent != nullptr && parent->left == node) {
            node = parent;
            parent = node->parent;
        }

        return parent;
    }

    /*
        print tree in UNIX file format
    */
    void printTree(Node *node, string prefix, bool isLeft) {
        if (node != nullptr) {
            cout<<prefix;
            cout<<(isLeft ? "|--":"|__");

            cout<<node->key<<endl;

            printTree(node->left, prefix + (isLeft ? "|   " : "    "), true);
            printTree(node->right, prefix + (isLeft ? "|   " : "    "), false);

        }
    }

    /*
        Case 1: There are not children to the node 
        Case 2: There is one child to the node
        Case 3: There are two children to the node    
    */
    void deleteNode(Node* node) {
        if (node->left == nullptr and node->right == nullptr) {
            auto parent = node->parent;
            if (parent->left == node) {
                parent->left = nullptr;
            } else if (parent->right == node) {
                parent->right = nullptr;
            }
            node->parent = nullptr;
        } else if (node->left != nullptr and node->right != nullptr) {
            Node* successor = node->right;
            Node* parent = node->parent;

            node->right->parent = parent;
            node->parent = successor;
            node->parent = nullptr;

        } else if (node->left != nullptr) {
            auto parent = node->parent;
            if (parent->left == node) {
                parent->left = node->left;                                
            } else {
                parent-> right = node->left;                
            }
            node->left->parent = parent;
            node->parent=nullptr;
        } else if (node->right != nullptr) {
            auto parent = node->parent;

            if (parent->left == node) {
                parent->left = node->right;
            } else {
                parent->right = node->right;
            }
            node->right->parent = parent;
            node->parent = nullptr;
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

//   tree.printTree(tree.root,"", false);
//   tree.recursiveInorderWalk(tree.root);

//   debug() << tree.findMax(tree.root);
//   debug() << tree.findMin(tree.root);

//   tree.printParentPath(tree.root->left->right->right);

     debug() << tree.findSuccessor(tree.root->left->left);
     debug() << tree.findPredessor(tree.root);
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
