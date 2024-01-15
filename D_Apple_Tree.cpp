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
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

using namespace std;
map<int, int> visited;
map<int, vector<int>> graph;
map<int, int> leaf;
void dfs(int start)
{
    // cout << start << " ";
    visited[start] = 1;
    if (graph[start].size() == 1 and start != 1)
        leaf[start] = 1;
    for (auto child : graph[start])
    {
        if (!visited[child])
            dfs(child), leaf[start] += leaf[child];
    }
}

void initial()
{
    visited.clear();
    leaf.clear();
    graph.clear();
}
void solve()
{
    initial();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    dfs(1);
    int m;
    cin >> m;
    if (leaf[1] == 0)
        leaf[1] = 1;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        // debug(leaf[x]);
        // debug(leaf[y]);
        cout << leaf[x] * leaf[y] << endl;
    }
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    // debug(t);
    while (t--)
        solve();
    return 0;
}