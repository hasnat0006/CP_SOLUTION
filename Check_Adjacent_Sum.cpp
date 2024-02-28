//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|02|2024 20:38:53            !//
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
    int n, q, x;
    cin >> n >> q;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
        cin >> x, mp[x].push_back(i), a[i] = x;
    // dbg(a);
    // dbg(mp);
    // sort(vf(a));
    int total_sum = 2 * accumulate(vf(a), 0LL);
    while (q--) {
        map<int, int> vis;
        cin >> x;
        int f = 0;
        int need = total_sum - x;
        // dbg(total_sum, x, need);
        for (int i = 0; i < n; i++) {
            int val = a[i];
            // dbg(i, val, need - val);
            if (mp[need - val].size() > 0) {
                if (mp[need - val][0] == i && mp[need - val].size() == 1)
                    continue;
                // dbg(i, need - val, mp[need - val]);
                vis[i] = 1;
                int id = 0;
                for (auto j : mp[need - val]) {
                    if (j != i) {
                        vis[j] = 1;
                        id = j;
                        // dbg(id);
                        break;
                    }
                }
                // dbg(id, a[i], a[id], val);
                // dbg(vis);
                cout << a[i] << " ";
                for (int j = 0; j < n; j++)
                    if (!vis[j])
                        cout << a[j] << " ";
                cout << a[id] << endl;
                f = 1;
                break;
            }
        }
        if (!f)
            cout << "-1" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}