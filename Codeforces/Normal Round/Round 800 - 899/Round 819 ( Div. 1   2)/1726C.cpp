//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|02|2024 17:01:04            !//
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

class DisjointSet {
   public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findUPar(parent[u]);
    }
    void unionBySize(int u, int v) {
        int pU = findUPar(u);
        int pV = findUPar(v);
        if (pU == pV)
            return;
        if (size[pU] < size[pV])
            swap(pU, pV);
        parent[pV] = pU;
        size[pU] += size[pV];
    }
};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    DisjointSet dsu(2 * n);
    stack<int> st;
    map<int, int> open;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(')
            st.push(i + 1);
        else {
            open[st.top()] = i + 1, st.pop();
        }
    }
    vector<bool> vis(2 * n + 1, false);
    for (int i = 1; i <= 2 * n; i++) {
        if (vis[i])
            continue;
        else {
            int j = i;
            while (j <= 2 * n and !vis[j] and !vis[open[j]]) {
                vis[j] = vis[open[j]] = true;
                dsu.unionBySize(i, j);
                dsu.unionBySize(i, open[j]);
                j = open[j] + 1;
            }
        }
    }
    set<int> ans;
    for (int i = 1; i <= 2 * n; i++)
        ans.insert(dsu.findUPar(i));
    cout << ans.size() << endl;
    dbg(ans);
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