//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 01:42:21            !//
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

string s;
map<int, vector<int>> adj;
vector<int> vis;
int cnt = 0;

pair<int, int> dfs(int start) {
    vis[start] = 1;
    pair<int, int> color;
    s[start - 1] == 'B' ? color.first++ : color.second++;
    for (auto i : adj[start]) {
        if (vis[i] == 0) {
            pair<int, int> temp = dfs(i);
            color.first += temp.first;
            color.second += temp.second;
        }
    }
    if (color.first == color.second)
        cnt++;
    return color;
}

void solve() {
    vis.clear();
    vis.resize(4005, 0);
    adj.clear();
    cnt = 0;
    s.clear();
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    cin >> s;
    dfs(1);
    cout << cnt << endl;
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