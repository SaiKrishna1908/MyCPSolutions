#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

const int MAXN = 100007;
vector<int> v(MAXN);
vector<int> dp(MAXN);
int n;

void print_vec(vector<int> arr)
{
    for (auto itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}

/*

Type: Dp Tabulation
1. How many states will be there in my dp ?
-> 1D array.

2. What does each state in my dp represent ?
-> dp[i] represents the minimum cost to reach ith stone

3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?
-> dp[new_stone] = min(dp[new_stone], dp[current_stone] + abs(cost(jump)))

   here new_stone can be current_stone+1 or current_stone+2
*/

void run()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n, INF);

    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {        
        for (int j : {i + 1, i + 2})
        {
            if (j < n)
            {
                dp[j] = min(dp[j], dp[i] + abs(v[j] - v[i]));
            }
        }
    }

    cout<<dp[n-1]<<endl;
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
