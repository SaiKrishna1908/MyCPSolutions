#include <iostream>
#include <vector>
using namespace std;

void solve()
{

    int n;

    // n = 7
    cin >> n;
    vector<int> a(n);

    // Initialize Dp
    // This dp has 2 states. L & R.
    // dp[i][j] gives the maximum coins that can be obtained in interval
    // i and j
    vector<vector<int>> dp(n, vector<int>(n));

    // a = [3,4,6,5,10,9,15]
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    // [l = 15,9,10,5... ]
    for (int l = n - 1; l >= 0; l--)
    {
        // l = 15; [r = 15]
        // l = 9; [r=9,15]
        for (int r = l; r < n; r++)
        {

            /*
             For every interval we calculate the maximum coins
             we can obtain. This can be done by considering which
             is the last coin to be popped. i below in a given range
             [l,r] denotes the last bubble.
            */
            for (int i = l; i <= r; i++)
            {
                dp[l][r] = max(dp[l][r], (l - 1 < 0 ? 1 : a[l - 1]) * a[i] * (r + 1 >= n ? 1 : a[r + 1]) +
                                             (i - 1 < 0 ? 0 : dp[l][i - 1]) + (i + 1 >= n ? 0 : dp[i + 1][r]));
                
            }
        }
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<(dp[0][n-1])<<endl;
}

int main(int argc, char **argv)
{

    solve();
}