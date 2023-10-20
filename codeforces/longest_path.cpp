  #include <iostream>
  #include <bits/stdc++.h>

  using namespace std;
  using namespace std::chrono;

  #define ll long long
  #define all(v) v.begin(), v.end()

  const int MAX = 1e5+7;   
  vector<int> edges[MAX];
  bool isvisited[MAX];

  // store distances in a dp 
  int dist[MAX];
  int indegree[MAX];

  void print_neighbours(vector<int> nei) {
    cout<<"neighbours are"<<endl;
    for(int i : nei) {
      cout<<i<<" "<<endl;
    }
  }

  void dfs(int vertex) {
      /*
         1. set isvisited to true
         2. loop through the neighbour and perform dfs
      */

     isvisited[vertex] = true;

     for(int neighbour : edges[vertex]) {       
       dist[neighbour] = max(dist[neighbour], dist[vertex] + 1);

       indegree[neighbour]--;

       if (indegree[neighbour] == 0) {
         dfs(neighbour);
       }       
     }
  }

  void run() {
    

    int n,m;
    cin>>n>>m;  

    cin.clear();

    for(int i=0;i<m;++i) {      
        
        int v1,v2;      
        cin>>v1>>v2;       
        edges[v1].push_back(v2);           
        indegree[v2]++;
    }  
    int max_len = 0;

    for(int i=1;i<=n;i++) {
      if (!isvisited[i] && indegree[i] == 0) {        
        dfs(i);
      }        
    }

    for (int i=1;i<=n;i++) {
      max_len = max(max_len, dist[i]);
    }
    
    cout<<max_len<<endl;
  }


  int main() {

    cin.tie(0);
    cin.sync_with_stdio(false);
      

    auto start = high_resolution_clock::now();
    
    run();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // cout<<"time: "<<duration.count()/1e6<<endl;
  }
