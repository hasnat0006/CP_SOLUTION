//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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
    int n, k;
    cin >> n >> k;
    DisjointSet dsu(n);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if (u > n or v > n) {
            ans++;
            continue;
        }
        if (type == 1) {
            if (dsu.findUPar(u) != dsu.findUPar(v) and
                (dsu.findUPar(u) != u or dsu.findUPar(v) != v))
                ans++;
            else
                dsu.unionBySize(u, v);
        }
        else {
            if (dsu.findUPar(u) == dsu.findUPar(v))
                ans++;
            else {
                if (dsu.findUPar(u) == u and dsu.findUPar(v) == v) {
                    dsu.parent[u] = -1;
                    dsu.parent[v] = -2;
                }
                
            }
        }
        cout << i + 1 << " -> " << ans << "\n";
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}