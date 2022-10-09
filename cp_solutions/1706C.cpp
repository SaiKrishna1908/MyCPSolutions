#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

const int MAX = 1e5;
int a[MAX];
ll dp[MAX]; 

void print_vec(vector<int> arr)
{
    for (auto itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}

ll compute_min_cost(int index, int n, bool should_include_three)
{
    if (dp[index] != -1) {
        return dp[index];
    }
    if (index >= n - 1)
    {
        return -1;
    }
    else
    {        
        ll needed = max(a[index-1], a[index+1]) - a[index]  + 1;
        if (a[index-1] < a[index] && a[index+1] < a[index]) {
            needed = 0;
        }
        ll jump_2_cost=  compute_min_cost(index + 2, n, should_include_three);

        ll jump_3_cost = -1; 
        if (should_include_three) {
            jump_3_cost=  compute_min_cost(index + 3, n, should_include_three);
        }        

        if (jump_2_cost != -1 && jump_3_cost != -1) {
            int res = needed +  min(jump_2_cost, jump_3_cost);
            dp[index] = res;
            return  res;
        } else if (jump_2_cost == -1 && jump_3_cost == -1) {
            dp[index] = needed;
            return needed;
        }
        
        int res = needed + max(jump_2_cost, jump_3_cost);
        dp[index] = res;
        return res;
    }
}

void run()
{

    int t;
    cin >> t;

    while (t-- > 0)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;        

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n == 3)
        {
            cout<< max(0, max(a[0], a[2]) - a[1]  + 1)<<endl;
            continue;
        }

        ll cost_1 = compute_min_cost(1, n, true);
        ll cost_2 = compute_min_cost(2, n, false);

        int min_cost = min(cost_1, cost_2);

        

        cout << min_cost << endl;
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
