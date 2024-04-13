//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|04|2024 00:20:19            !//
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

typedef pair<int, int> pairi;
int N = 20000 + 5;
vector<vector<pairi>> adj(N);
vector<int> disSrc(N, inf), levelSrc(N, 0), disDes(N, inf), levelDes(N, 0);

void dijkstraSrc(int src) {
    priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
    disSrc[src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        for (auto i : adj[top.second]) {
            int v = i.first;
            int wt = i.second;
            if (disSrc[v] > disSrc[top.second] + wt) {
                disSrc[v] = disSrc[top.second] + wt;
                pq.push({disSrc[v], v});
                levelSrc[v] = levelSrc[top.second] + 1;
            }
        }
    }
}

vector<bool> vis(N, false);

int dfs(int node) {
    if (node == 1)
        return 1;
    vis[node] = true;
    for (auto i : adj[node]) {
        int v = i.first;
        if (!vis[v]) {
            return 1 + dfs(v);
        }
    }
    return 0;
}

void dijkstraDes(int src) {
    priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
    disDes[src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        for (auto i : adj[top.second]) {
            int v = i.first;
            int wt = i.second;
            if ((levelDes[top.second] + 1 + levelSrc[v]) % 2 == 0 and
                disDes[v] > disDes[top.second] + wt) {
                disDes[v] = disDes[top.second] + wt;
                pq.push({disDes[v], v});
                levelDes[v] = levelDes[top.second] + 1;
            }
        }
    }
}

void solve() {
    int n;
    while (cin >> n) {
        adj.clear();
        adj.resize(n + 1);
        disSrc.clear();
        disSrc.resize(n + 1, inf);
        levelSrc.clear();
        levelSrc.resize(n + 1, 0);
        disDes.clear();
        disDes.resize(n + 1, inf);
        levelDes.clear();
        levelDes.resize(n + 1, 0);
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dijkstraSrc(1);
        dijkstraDes(n);
        dbg(levelSrc);
        dbg(levelDes);
        cout << dfs(3) << endl;
        cout << (disDes[1] == inf ? -1 : disDes[1]) << endl;
    }
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