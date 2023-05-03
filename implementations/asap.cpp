#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

map<char, int> op_map {{'+', 1}, {'-', 1}, {'*', 1}, {'/', 1}, {'O', 0}};

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

struct Node {
    int id;
    vector<int> preds;
    vector<int> succs;
    char op;

    Node(int n, vector<int> p, vector<int> s, char optr) {
        id = n;
        preds = p;
        succs = s;
        op = optr;
    }
};

void run() {
  int n;

  cin>>n;

  map<int,Node> nodes;

  for(int i=0;i<n;i++) {
    int id, predc, succ;
    char op;

    cin>>id>>predc>>succ;
    cin>>op;

    vector<int> preds;
    vector<int> succs;

    for(int i=0;i<predc;i++) {
        int input;
        cin>>input;
        preds.push_back(input);        
    }

    for(int i=0;i<succ;i++) {
        int input;
        cin>>input;
        succs.push_back(input);        
    }
    
    auto node = Node(id, preds, succs, op);    
    nodes.insert(make_pair(id, node));
  }

  deque<pair<int, int>> dq;

  dq.push_back(make_pair(0, 0));

  int max_time = 0;
  map<int, int> result;

  while(!dq.empty()) {
    auto current_node = nodes.at(dq.front().first);
    int current_cost = dq.front().second + op_map[current_node.op];
    max_time = max(max_time, current_cost);
    
    result[current_node.id] = max(result[current_node.id], max_time);
    for(auto neighbour: current_node.succs) {
        dq.push_back(make_pair(neighbour, max_time));
    }
    dq.pop_front();
  }

  cout<<"Node, Time"<<endl;
  for(auto elem : result) {
    cout<<elem.first<<" "<<elem.second<<endl;
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