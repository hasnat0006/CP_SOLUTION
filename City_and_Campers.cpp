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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;
class DisjointSet {
   public:
    vector<int> parent, size;
    set<pair<int, int>> ans;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i, ans.insert({1, i});
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
        if (size[pU] < size[pV]) {
            parent[pU] = pV;
            size[pV] += size[pU];
        }
        else {
            parent[pV] = pU;
            size[pU] += size[pV];
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    DisjointSet dsu(n);
    map<int,int> mp;
    for(int i = 1; i <= n; i++) {
        mp[i] = 1;
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        dsu.ans.erase({dsu.size[dsu.findUPar(u)], u});
        dsu.ans.erase({dsu.size[dsu.findUPar(v)], v});
        dsu.ans.erase({mp[dsu.findUPar(u)], dsu.findUPar(u)});
        dsu.ans.erase({mp[dsu.findUPar(v)], dsu.findUPar(v)});
        dsu.unionBySize(u, v);
        dsu.ans.insert({dsu.size[dsu.findUPar(u)], dsu.findUPar(u)});
        mp[dsu.findUPar(u)] = dsu.size[dsu.findUPar(u)];
        cout << dsu.ans.rbegin()->first - dsu.ans.begin()->first << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}