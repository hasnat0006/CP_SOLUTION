//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void print(priority_queue<int, vector<int>, less<int>> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> all_color[k + 1];
    for (int i = 1; i <= k; i++)
        all_color[i].pb(-1);
    for (int i = 0; i < n; i++)
        all_color[v[i]].pb(i);
    for (int i = 1; i <= k; i++)
        all_color[i].pb(n);
    if(all_color[v[0]].size() == n + 2) {
        cout << 0 << endl;
        return;
    }
    unordered_map<int, pair<int, int>> max_diff_of_color;
    int ans = inf;
    for (int i = 1; i <= k; i++) {
        dbg(i, all_color[i]);
        priority_queue<int, vector<int>, less<int>> s;
        for (int j = 1; j < all_color[i].size(); j++) {
            int max_diff = all_color[i][j] - all_color[i][j - 1];
            if (max_diff != 1)
                s.push(max_diff - 1);
        }
        // print(s);
        int top = s.top();
        s.pop();
        if (s.size()) {
            int ndTop = s.top();
            int nibo = max({top / 2, ndTop});
            dbg(top, ndTop, nibo);
            ans = min(ans, nibo);
        }
        else
            ans = min(ans, top / 2);
        dbg(i, ans, top, s.size());
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}