#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
typedef vector<int> vi;


void print(vector<int> vi) {

    for(auto i: vi) {
        cout<<i<<" ";
    }

    cout<<endl;
}
//Did you REAALLY consider sample tests?
void solve(int tc) {

    // contains the bi-table with 2 rows
    string s[2];
    int n;
    cin >> n;
    cin >> s[0] >> s[1];

    // declare dp
    vi dp(n + 1, 0);

    // create a array with two elements -1,-1
    vi last(2, -1);
    


    auto take = [&](int i, bool take0, bool take1) {
        int MEX = 0;

        // Get MEX value
        if (take0) {
            if (take1) MEX = 2;
            else MEX = 1;
        }
        
        // current segment
        int index = i;

        // take0 will be minimum of i, last[0] : last[0] contains most recent index which has 0
        if (take0) index = min(index, last[0]);

        // take1 will be minimum of i, last[1] : last[1] contains most recent index which has 1
        if (take1) index = min(index, last[1]);
        
        if (index != -1) return MEX + dp[index - 1];
        return -100000;
    };
    
    // Iterate for n columns of a table
    FOR(i, 1, n) {

        print(last);

        // last[0][s[0][i-1] - '0'] --> contains the most recent zero index
        // last[1][s[1][i-1] - '0'] --> contains the most recent one index
        rep(j, 0, 2) last[s[j][i-1] - '0'] = i;

        
        dp[i] = dp[i-1];

        // Meaning add a column which has recent zero
        dp[i] = max(dp[i], take(i, 1, 0));
        // Meaning add a column which has recent one        
        dp[i] = max(dp[i], take(i, 0, 1));
        // Meanning add a column which has recent one and zero
        dp[i] = max(dp[i], take(i, 1, 1));
    }
    
    cout << dp[n] << "\n";
}
 
int main() {
    int tests;
    cin >> tests;
    FOR(test, 1, tests) {
        solve(test);
    }
}