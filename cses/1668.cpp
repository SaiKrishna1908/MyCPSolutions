#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN 100007

vector<vector<int>> graph(MAXN);

vector<bool> isVisited(MAXN);

vector<int> color(MAXN);

bool isPossible = true;

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

bool dfs(int vertex, int previousGroup)
{
  if (color[vertex] != 0)
  {
    return color[vertex] != previousGroup;
  }

  int currentGroup = previousGroup == 1 ? 2 : 1;
  color[vertex] = currentGroup;
  for (int i = 0; i < graph[vertex].size(); i++)
  {

    if (!dfs(graph[vertex][i], currentGroup))
    {
      return false;
    }
  }

  return true;
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

  bool isPossible = true;

  for (int i = 1; i <= n && isPossible; i++)
  {
    isPossible = dfs(i, 0);
  }

  if (isPossible)
  {
    for (int i = 1; i <= n; i++)
    {
      cout << color[i] << " ";
    }
  }
  else
  {
    cout << "IMPOSSIBLE" << endl;
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
