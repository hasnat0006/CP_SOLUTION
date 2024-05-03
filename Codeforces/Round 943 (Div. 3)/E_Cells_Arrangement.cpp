//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|05|2024 22:38:56            !//
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

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= (n + 1) / 2; i += 2) {
        ans.push_back({1, i});
    }
    dbg(ans);
    ans.push_back({n, n});
    int k = ans.size();
    for (int i = k + 1, j = 1, id = n - 1; i <= n; i++, j++) {
        if (j % 2)
            ans.push_back({id, n});
        else {
            ans.push_back({id, 1});
            id -= 2;
        }
    }
    dbg(ans);
    for(auto i : ans)
        cout << i.first << " " << i.second << endl;
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}