#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;


// void print(vector<pii> p ){

//     for (auto i : p) {
//         cout<<"<"<<i.first<<", "<<i.second<<">";
//     }
// }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // creates  a comparator for sorting a vector/set
        auto cmp = [](pii const &x, pii const &y) {
            return x > y;
        };
        set<pii, decltype(cmp)> a(cmp);

        // vector to store answer
        vector<pii> answer;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            if (ai > 0)
                a.emplace(ai, i + 1);
        }

        

        while (a.size() > 1) {            

            auto p1 = *a.begin();
            a.erase(a.begin());
            auto p2 = *a.begin();
            a.erase(a.begin());

            answer.emplace_back(p1.second, p2.second);

            // decrement first two social numbers by 1
            if (p1.first > 1) a.emplace(p1.first - 1, p1.second);
            if (p2.first > 1) a.emplace(p2.first - 1, p2.second);
        }
        cout << answer.size() << '\n';
        for (auto &p : answer) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }
}