#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

void print_vec(vector<int> arr)
{
    for (auto itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}

void run()
{
    int n;

    cin >> n;

    set<int> s;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }

    cout << s.size() << " ";
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
