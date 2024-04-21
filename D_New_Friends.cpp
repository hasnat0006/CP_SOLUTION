//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|04|2024 23:22:13            !//
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

class DisjointSet {
    vector<int> parent, size, minElement, maxElement, cntElement;

   public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        minElement.resize(n + 1);
        maxElement.resize(n + 1);
        cntElement.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = minElement[i] = maxElement[i] = i;
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
        cntElement[pU] += cntElement[pV];
        minElement[pU] = min(minElement[pU], minElement[pV]);
        maxElement[pU] = max(maxElement[pU], maxElement[pV]);
    }
    int getMinElementIntheSet(int u) { return minElement[findUPar(u)]; }
    int getMaxElementIntheSet(int u) { return maxElement[findUPar(u)]; }
    int getNumofElementIntheSet(int u) { return cntElement[findUPar(u)]; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DisjointSet dsu(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unionBySize(u, v);
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[dsu.findUPar(i)]++;
    }
    dbg(mp);
    int ans = 0;
    for (auto i : mp) {
        if (i.second > 2)
            ans += (i.second * (i.second - 1) / 2);
        else if (i.second == 2)
            ans++;
    }
    cout << ans - m << endl;
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