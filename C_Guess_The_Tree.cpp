//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|08|2024 12:43:06            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

set<pair<int, int>> ans;
int flag[1005];
map<pair<int, int>, int> p;

void dfs(int u, int v) {
    if (p[{u, v}] || p[{v, u}])
        return;
    p[{u, v}] = 1;
    p[{v, u}] = 1;
    cout << "? " << u << " " << v << endl;
    cout.flush();
    int x;
    cin >> x;
    if (x == u || x == v) {
        ans.insert({u, v});
        flag[x] = 1;
        return;
    }
    dfs(u, x);
    dfs(x, v);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        flag[i] = 0;
    }
    ans.clear();
    p.clear();
    for (int i = 1; i < n; i++) {
        if (!flag[i]) {
            dfs(i, n);
        }
    }
    cout << "! ";
    for (auto i : ans)
        cout << i.first << " " << i.second << ' ';
    cout << endl;
    cout.flush();
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}