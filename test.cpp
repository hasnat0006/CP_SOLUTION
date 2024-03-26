//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|03|2024 22:10:22            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

int dp[105][5];
vector<int> v;

int findAns(int id, int last) {
    if (id == -1)
        return 0;
    // last means ager index e konta use korsi
    // jodi ager last == v[id] or v[id] == 0 taile rest and day is count as rest
    // day
    if (dp[id][last] != -1)
        return dp[id][last];
    if (last == v[id] or v[id] == 0)
        return dp[id][last] = findAns(id - 1, 0);
    if (v[id] == 3) {
        // jodi last day rest hoi taile 2 ta possible exercise e korbe
        int rest = 0 + findAns(id - 1, 0);
        if (last == 0 or last == 4) {
            int one = 1 + findAns(id - 1, 1);
            int two = 1 + findAns(id - 1, 2);
            return dp[id][last] = max({one, two, rest});
        }
        else if (last != 2)
            return dp[id][last] = max(1 + findAns(id - 1, 2), rest);
        else if (last != 1)
            return dp[id][last] = max(1 + findAns(id - 1, 1), rest);
    }
    if (v[id] == 2) {
        int rest = findAns(id - 1, 0), two = 0;
        if (last != 2)
            two = 1 + findAns(id - 1, 2);
        return dp[id][last] = max(rest, two);
    }
    else if (v[id] == 1) {
        int rest = findAns(id - 1, 0), one = 0;
        if (last != 1)
            one = 1 + findAns(id - 1, 1);
        return dp[id][last] = max(rest, one);
    }
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << n - findAns(n - 1, 4) << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= 4; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}