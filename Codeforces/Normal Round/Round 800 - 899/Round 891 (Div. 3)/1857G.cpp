//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

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
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 998244353;
float pi = acos(-1);
int inf = 1e18;

int binaryExponentiation(int base, int power) ////O(log2(power))
{
    if (power == 0)
        return 1;
    int ans = binaryExponentiation(base, power / 2);
    if (power % 2 == 1)
        return (((ans * ans) % mod) * base) % mod;
    return (ans * ans) % mod;
}

class DisjointSet
{
public:
    vector<int> parent, sz;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int u) { return u == parent[u] ? u : parent[u] = findUPar(parent[u]); }
    void Union(int u, int v)
    {
        int uP = findUPar(u);
        int vP = findUPar(v);

        if (sz[uP] < sz[vP])
            swap(uP, vP);
        if (uP != vP)
        {
            parent[vP] = uP;
            sz[uP] += sz[vP];
        }
    }
};

void solve()
{
    int n, s;
    cin >> n >> s;
    int ans = 1;
    DisjointSet g(n);
    vector<pair<int, pair<int, int>>> ed;
    for (int i = 1; i < n; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        ed.push_back({wt, {u, v}});
    }
    sort(ed.begin(), ed.end());
    for (auto i : ed)
    {
        int uP = g.findUPar(i.second.first);
        int vP = g.findUPar(i.second.second);

        ans = (ans * binaryExponentiation(s - i.first + 1, g.sz[uP] * g.sz[vP] - 1)) % mod;
        g.Union(i.second.first, i.second.second);
    }
    cout << ans << "\n";
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}