//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 22:24:45            !//
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

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> wt(n + 1), profit(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> wt[i];
    for (int i = 1; i <= n; i++)
        cin >> profit[i];
    vector<int> pre(w + 1, 0), cur(w + 1, 0);
    for (int id = 1; id <= n; id++) {
        for (int wg = 1; wg <= w; wg++) {
            int notTake = pre[wg], take = 0;
            if (wg - wt[id] >= 0)
                take = profit[id] + pre[wg - wt[id]];
            cur[wg] = max(take, notTake);
        }
        pre = cur;
    }
    cout << pre[w] << endl;
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