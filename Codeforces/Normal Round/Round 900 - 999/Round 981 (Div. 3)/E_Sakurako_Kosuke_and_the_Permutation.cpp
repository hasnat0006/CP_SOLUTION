//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|10|2024 13:35:13            !//
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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

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
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll not_same = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    DisjointSet dsu(n);
    for (int i = 1; i <= n; i++) {
        dsu.unionBySize(i, v[i - 1]);
    }
    map<ll, ll> done;
    for (int i = 1; i <= n; i++) {
        int uPar = dsu.findUPar(i);
        if (!done.count(uPar)) {
            done[uPar] = 1;
            int sz = dsu.getNumofElementIntheSet(i);
            if (sz > 2)
                not_same += ceil(sz / 2.0) - 1;
        }
    }
    cout << not_same << '\n';
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