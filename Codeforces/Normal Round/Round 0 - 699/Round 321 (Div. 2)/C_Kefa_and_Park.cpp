//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

map<int, vector<int>> adj;
map<int, int> cat;
int n, m, x, u, v, ans = 0;

void dfs(int start, int parent, int cnt)
{
    if (cnt > m)
        return;
    int check = 0;
    for (auto child : adj[start])
    {
        if (child != parent)
        {
            check = 1;
            if (cat[child])
                dfs(child, start, cnt + 1);
            else
                dfs(child, start, 0);
        }
    }
    if (!check)
        ans++;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x, cat[i + 1] = x;

    for (int i = 0; i < n - 1; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    // debug(adj);
    dfs(1, -1, cat[1]);
    cout << ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}