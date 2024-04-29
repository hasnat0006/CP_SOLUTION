//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|04|2024 21:08:59            !//
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
const int N = 2e5 + 5;

map<int, int> white;
vector<int> adj[N];
vector<int> vis(N);
map<int, int> cntwhite;
set<int> ans;

void dfs(int src) {
    vis[src] = 1;
    int cnt = 0;
    for (auto i : adj[src]) {
        if (!vis[i]) {
            dfs(i);
            if (cntwhite[i])
                cnt++;
            cntwhite[src] += cntwhite[i];
        }
    }
    if (!white[src] and cnt >= (int)adj[src].size() - 1)
        ans.insert(src);
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        white[x]++, cntwhite[x]++;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(white.begin()->first);
    dbg(ans);
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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