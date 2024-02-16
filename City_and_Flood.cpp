//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA  cin.tie(NULL), 
#define HASNAT cout.tie(NULL)

int mod  = 1000000007;
int inf  = 1e18;

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

void solve()
{
    int n;
    cin >> n;
    DisjointSet dsu(n);
    int k;
    cin >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        dsu.unionBySize(u, v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(dsu.parent[i] == i){
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}