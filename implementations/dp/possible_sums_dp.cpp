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


/*
  Type: Bottom up DP

  1. How many states will be there in my dp ?
  -> 1

  2. What does each state in my dp represent ?
  -> dp[i] represents the number of ways sum i can be built with existing numbers

  3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?
  -> for coin in coins
  ->    for sum = totalSum; sum >= coin ; sum--
  ->        dp[sum] = dp[sum] + dp[sum - coin]
*/

void run()
{
    int n;

    cin >> n;

    vector<int> nums(n);
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= nums[i]; j--)
        {
            dp[j] += dp[j - nums[i]];
        }
    }

    for (int i = 1; i <= sum; i++)
    {
        cout << i << " " << dp[i] << endl;
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
