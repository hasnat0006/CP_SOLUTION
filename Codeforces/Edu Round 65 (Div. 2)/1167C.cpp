//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|02|2024 16:51:38            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

class DisjointSet {
    vector<int> parent, size, cntElement;

   public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        cntElement.resize(n + 1, 1);
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
        cntElement[pU] += cntElement[pV];
    }
    int getNumofElementIntheSet(int u) { return cntElement[findUPar(u)]; }
};

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    DisjointSet dsu(n);
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x == 0)
            continue;
        int u, v;
        cin >> u;
        for (int j = 1; j < x; j++) {
            cin >> v;
            dsu.unionBySize(u, v);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dsu.getNumofElementIntheSet(i) << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}