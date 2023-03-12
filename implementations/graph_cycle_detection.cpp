/*
    Write a Program to detect a cycle in the graph.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN 100007

vector<vector<int>> graph(MAXN);

vector<bool> isVisited(MAXN);

bool isCyclic(int vertex, int parent)
{
    isVisited[vertex] = true;

    for (int i = 0; i < graph[vertex].size(); i++)
    {
        if (!isVisited[graph[vertex][i]] && isCyclic(graph[vertex][i], vertex))
        {
            return true;
        }
        else if (graph[vertex][i] != parent && parent != -1)
        {
            return true;
        }
    }

    return false;
}

int main()
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

    int count = 0;
    bool hasCycle = false;

    for(int i=1;i<n && !hasCycle;i++) {
        if (!isVisited[i]) {
            bool hasCycle = isCyclic(i, -1);
        }    
    }    

    cout << hasCycle << endl;
}
