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
map<int, int> visited;
map<int, int> level;
map<int, int> parent;

void dfs(int start)
{
    visited[start] = 1;
    for (auto child : adj[start])
    {
        if (!visited[child])
        {
            parent[child] = start;
            level[child] = level[start] + 1;
            dfs(child);
        }
    }
}

void solve()
{
    int n, m, st;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        s.insert(x);
        s.insert(y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (m >= n)
    {
        cout << "NO\n";
        return;
    }
    set<int>::iterator it;
    it = s.begin();
    // cout << *it << endl;
    dfs(*it);
    // debug(visited);
    for (auto i : s)
    {
        if (!visited[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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