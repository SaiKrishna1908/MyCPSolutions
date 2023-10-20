#include <bits/stdc++.h>
 
using namespace std;

#define ll long long

const ll inf = 1e9;
 
void solve()
{
    int n;
    cin >> n;
 
    const int A = 1e9 + 1;
    int minL = A, costL = A;
    int maxR = 0, costR = A;
    int maxLen = 0, costLen = A;


    // should be least with least cost
    pair<int,int> lseg = make_pair(inf, inf);

    // should be max with least cost
    pair<int, int> hseg = make_pair(-inf, -inf);

    // should be max range with lease cost
    pair<int, int> segment = make_pair(-inf, -inf);


    for (int i = 0; i < n; i++)
    {

        // 4, 7, 3
        int l, r, c;
        cin >> l >> r >> c;
        
        // minimize l and c
        lseg = min(lseg, make_pair(l, c));
        // maximize r and minimize c
        hseg = max(hseg, make_pair(r, -c));
        // maximize range and 
        segment = max(segment, make_pair(r-l+1, -c));

        int ans = lseg.second - hseg.second;

        // this is the longest segment
        if (segment.first == hseg.first-lseg.first+1) {
            ans = min(ans, -segment.second);
        }
    
        cout << ans << "\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}