#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN 100007

vector<vector<int>> graph(MAXN);

bool found_cycle = false;

bool isVisited[MAXN];
vector<bool> isVisitedPrint(MAXN);

vector<int> parent_vertex(MAXN);

int sv, ev;

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

bool dfs(int vertex, int parent)
{
  isVisited[vertex] = true;
  parent_vertex[vertex] = parent;

  for (int i = 0; i < graph[vertex].size(); i++)
  {
    int neighbour = graph[vertex][i];

    if (neighbour == parent) continue;

    // Bounding Condition
    if (isVisited[neighbour] && (parent != neighbour))
    {
      // sv is already visited, so it must be the starting vertex
      sv = neighbour;

      // present vertex is the last vertex
      ev = vertex;
      return true;
    }
    if (!isVisited[neighbour])
    {
      if (dfs(neighbour, vertex)) {
        return true;
      }      
    }
  }

  return false;
}

void run()
{
  int n, m;

  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a, b;

    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int i;

  for (i = 1; i <= n; i++)
  {
    if (!isVisited[i])
    {
      found_cycle = dfs(i, -1);
    }

    if (found_cycle)
    {
      break;
    }
  }

  if (!found_cycle)
  {
    cout << "IMPOSSIBLE" << endl;
  }
  else
  {    
    vector<int> sol;    
    int tv = ev;
    sol.push_back(ev);
    while(tv != sv && tv != -1) {      
      sol.push_back(parent_vertex[tv]);
      tv=parent_vertex[tv];
    }        

    sol.push_back(ev);

    cout<<sol.size()<<endl;

    for(int i=0;i<sol.size();i++) {
      cout<<sol[i]<<" ";
    }
  }
}

int main()
{

  cin.tie(0);
  cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  run();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
