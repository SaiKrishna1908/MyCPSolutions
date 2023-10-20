#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

const int MAX = 1007;
const int MOD = 1e9 + 7;

int grid[MAX][MAX];

void run()
{
    int h, w;

    cin >> h >> w;

    /*
        1 -> wall
        0 -> free
    */

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char input;
            cin >> input;
            if (input == '#')
            {
                grid[i][j] = 1;
            }
        }
    }

    // dp[i][j] represents the number of ways to reach grid[i][j]

    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i + 1 < h && !grid[i + 1][j])
            {

                dp[i + 1][j] += dp[i][j];

                if (dp[i + 1][j] >= MOD)
                {
                    dp[i + 1][j] = dp[i + 1][j] - MOD;
                }
            }

            if (j + 1 < w && !grid[i][j + 1])

            {
                dp[i][j + 1]  += dp[i][j];

                if (dp[i][j + 1] >= MOD)
                {
                    dp[i][j + 1] = dp[i][j + 1] - MOD;
                }
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;
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
