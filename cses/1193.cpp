#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define MAXN 1007

vector<vector<char>> graph(MAXN, vector<char>(MAXN));

bool isVisited[MAXN][MAXN];

pair<int, int> start_index;
pair<int, int> end_index;

vector<vector<pair<int, int>>> parent(MAXN,vector<pair<int,int>>(MAXN));

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int n, m;

deque<pair<int, int>> dq;

bool isValid(int x, int y)
{
  if (x >= n)
    return false;
  if (y >= m)
    return false;
  if (x < 0 || y < 0)
    return false;
  if (graph[x][y] == '#')
    return false;

  return true;
}

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

void bfs()
{

  while (!dq.empty())
  {
    auto current_vertex = dq.front();
    dq.pop_front();    

    if (current_vertex.first == end_index.first && current_vertex.second == end_index.second)
    {
      dq.clear();
      break;
    }
    for (int i = 0; i < 4; i++)
    {
      int newX = current_vertex.first + dx[i];
      int newY = current_vertex.second + dy[i];

      if (!isVisited[newX][newY] && isValid(newX, newY))
      {
        isVisited[newX][newY] = true;
        parent[newX][newY] = make_pair(current_vertex.first, current_vertex.second);
        dq.push_back(make_pair(newX, newY));
      }
    }
  }
}

void print_path()
{
  vector<char> op;
  pair<int, int> temp = end_index;
  while (temp.first != start_index.first || temp.second != start_index.second)
  {
    int dxc = parent[temp.first][temp.second].first - temp.first;
    int dyc = parent[temp.first][temp.second].second - temp.second;

    if (dxc < 0)
    {
      op.push_back('D');
    }
    else if (dxc > 0)
    {
      op.push_back('U');
    }
    else if (dyc < 0)
    {
      op.push_back('R');
    }
    else if (dyc > 0)
    {
      op.push_back('L');
    }

    temp = parent[temp.first][temp.second];
  }

  cout << "YES" << endl;
  string ops = string(op.rbegin(), op.rend());
  cout << op.size() << endl;
  cout << ops << endl;
}

void run()
{

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;

      cin >> c;

      graph[i][j] = c;

      if (graph[i][j] == 'A')
      {
        start_index = make_pair(i, j);
      }
      else if (graph[i][j] == 'B')
      {
        end_index = make_pair(i, j);
      }
    }
  }

  dq.push_back(make_pair(start_index.first, start_index.second));
  isVisited[start_index.first][start_index.second] = true;
  bfs();

  if (!isVisited[end_index.first][end_index.second])
  {
    cout << "NO" << endl;
  }
  else
  {
    print_path();
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
