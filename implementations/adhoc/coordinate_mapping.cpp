#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

map<int,int> co_map;

void print_vec(vector<int> arr)
{
    for (auto itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}

void map_co_ordinates(vector<int> &vec)
{

    sort(vec.begin(), vec.end());

    for (auto v : vec)
    {
        if (!co_map.count(v))
        {
            co_map.insert(make_pair(v,co_map.size()+1));
        }
    }
}

void run()
{

    int n;
    cin >> n;

    vector<int> vec(n);

    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }

    map_co_ordinates(vec);

    for(auto e : co_map) {
        cout<<e.first<<" "<<e.second<<endl;
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
