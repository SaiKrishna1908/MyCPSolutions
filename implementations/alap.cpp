/*
    Compile file
    g++ alap.cpp -o ./a
    run file
    a
*/

#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using namespace std::chrono;

unordered_map<char, vector<char>> get_depends_on(vector<char> tasks, vector<pair<char, char>> dependencies);
unordered_map<char, int> task_scheduler(vector<char> tasks, vector<pair<char, char>> dependencies, int delay, int tasks_per_cycle);

#define ll long long
#define all(v) v.begin(), v.end()

map<char, int> op_map{{'+', 1}, {'-', 1}, {'*', 1}, {'/', 1}, {'O', 0}};

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

struct Node
{
  int id;
  vector<int> preds;
  vector<int> succs;
  char op;

  Node(int n, vector<int> p, vector<int> s, char optr)
  {
    id = n;
    preds = p;
    succs = s;
    op = optr;
  }
};

void runAlap()
{
  cout << "Waiting for input..." << endl;
  int n;

  cin >> n;

  map<int, Node> nodes;

  for (int i = 0; i < n; i++)
  {
    int id, predc, succ;
    char op;

    cin >> id >> predc >> succ;
    cin >> op;

    vector<int> preds;
    vector<int> succs;

    for (int i = 0; i < predc; i++)
    {
      int input;
      cin >> input;
      preds.push_back(input);
    }

    for (int i = 0; i < succ; i++)
    {
      int input;
      cin >> input;
      succs.push_back(input);
    }

    auto node = Node(id, preds, succs, op);
    nodes.insert(make_pair(id, node));
  }

  stack<pair<int, int>> st;

  st.push(make_pair(0, 0));

  int max_time = 0;
  map<int, int> result;

  while (!st.empty())
  {

    auto node = st.top();
    st.pop();
    auto current_node = nodes.at(node.first);
    int current_cost = node.second + op_map[current_node.op];
    max_time = max(max_time, current_cost);

    result[current_node.id] = max(result[current_node.id], max_time);
    for (auto neighbour : current_node.succs)
    {
      st.push(make_pair(neighbour, max_time));
    }
  }

  cout << "Node, Time" << endl;
  for (auto elem : result)
  {
    if (elem.first == 0) {
      cout << elem.first << "\t" << 1 << endl;  
    } else {
      cout << elem.first << "\t" << elem.second << endl;
    }    
  }
}

void runAsap()
{
  cout << "Waiting for input..." << endl;
  int n;

  cin >> n;

  map<int, Node> nodes;

  for (int i = 0; i < n; i++)
  {
    int id, predc, succ;
    char op;

    cin >> id >> predc >> succ;
    cin >> op;

    vector<int> preds;
    vector<int> succs;

    for (int i = 0; i < predc; i++)
    {
      int input;
      cin >> input;
      preds.push_back(input);
    }

    for (int i = 0; i < succ; i++)
    {
      int input;
      cin >> input;
      succs.push_back(input);
    }

    auto node = Node(id, preds, succs, op);
    nodes.insert(make_pair(id, node));
  }

  deque<pair<int, int>> dq;

  dq.push_back(make_pair(0, 0));

  int max_time = 0;
  map<int, int> result;

  while (!dq.empty())
  {
    auto current_node = nodes.at(dq.front().first);
    int current_cost = dq.front().second + op_map[current_node.op];
    max_time = max(max_time, current_cost);

    result[current_node.id] = max(result[current_node.id], max_time);
    for (auto neighbour : current_node.succs)
    {
      dq.push_back(make_pair(neighbour, max_time));
    }
    dq.pop_front();
  }

  cout << "Node, Time" << endl;
  for (auto elem : result)
  {
    if (elem.first == 0)
    {
      cout << elem.first << " " << 1 << endl;
    }
    else
    {
      cout << elem.first << " " << elem.second << endl;
    }
  }
}

void run3()
{
  cout << "Waiting for input..." << endl;
  int n, m;
  cin >> n >> m;

  vector<char> tasks(n);
  vector<pair<char, char>> dependencies(m);

  for (int i = 0; i < n; i++)
  {
    cin >> tasks[i];
  }

  for (int i = 0; i < m; i++)
  {
    char a, b;
    cin >> a >> b;
    dependencies.push_back(make_pair(a, b));
  }
  int delay = 2;
  int tasks_per_cycle = 2;
  unordered_map<char, int> start_times = task_scheduler(tasks, dependencies, delay, tasks_per_cycle);
  for (auto start_time : start_times)
  {
    cout << start_time.first << ": " << start_time.second << endl;
  }
}

unordered_map<char, vector<char>> get_depends_on(vector<char> tasks, vector<pair<char, char>> dependencies)
{
  unordered_map<char, vector<char>> depends_on;
  for (auto task : tasks)
  {
    depends_on[task] = vector<char>();
  }
  for (auto pair : dependencies)
  {
    depends_on[pair.first].push_back(pair.second);
  }
  return depends_on;
}

unordered_map<char, int> task_scheduler(vector<char> tasks, vector<pair<char, char>> dependencies, int delay, int tasks_per_cycle)
{
  unordered_map<char, vector<char>> depends_on = get_depends_on(tasks, dependencies);
  unordered_map<char, int> start_times;
  for (auto task : tasks)
  {
    start_times[task] = -1;
  }
  deque<char> current_cycle;
  for (auto task : tasks)
  {
    if (depends_on[task].empty())
    {
      current_cycle.push_back(task);
    }
  }
  int current_time = 0;
  while (!current_cycle.empty())
  {
    int num_tasks_to_execute = min((int)current_cycle.size(), tasks_per_cycle);
    for (int i = 0; i < num_tasks_to_execute; i++)
    {
      char task = current_cycle.front();
      current_cycle.pop_front();
      start_times[task] = current_time;
      for (auto dependent_task : tasks)
      {
        auto it = find(depends_on[dependent_task].begin(), depends_on[dependent_task].end(), task);
        if (it != depends_on[dependent_task].end())
        {
          depends_on[dependent_task].erase(it);
          if (depends_on[dependent_task].empty())
          {
            current_cycle.push_back(dependent_task);
          }
        }
      }
    }
    current_time += delay;
  }
  return start_times;
}

int main()
{

  cin.tie(0);
  cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  int i;
  cout << "Enter 1 for ALAP, 2 for ASAP, 3 for " << endl;
  cin >> i;

  switch (i)
  {
  case 1:
    runAlap();
    break;
  case 2:
    runAsap();
    break;
  case 3:
    run3();
    break;
  default:
    break;
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "time: " << duration.count() / 1e6 << endl;
}
