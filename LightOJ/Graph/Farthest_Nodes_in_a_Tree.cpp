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
const int last = 10005;

unordered_map<int, vector<pair<int, int>>> adj;
// vector<pair<int, int>> adj[last];
unordered_map<int, int> cost;
// vector<int> cost(last);
int sobarlast;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    unordered_map<int, int> visited;
    visited[start] = 1;
    int mx = -1;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (auto child : adj[k])
        {
            if (!visited[child.first])
            {
                cost[child.first] = cost[k] + child.second;
                q.push(child.first);
                visited[child.first] = 1;
                if (cost[child.first] > mx)
                    mx = cost[child.first], sobarlast = child.first;
            }
        }
    }
}

void reset()
{
    sobarlast = 0, cost.clear(), adj.clear();
}

void solve()
{
    reset();
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
        adj[v].pb({u, wt});
    }
    bfs(0);
    // debug(cost);
    // debug(sobarlast);
    cost.clear();
    bfs(sobarlast);
    // debug(cost);
    // debug(sobarlast);
    cout << cost[sobarlast] << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << "Case " << i + 1 << ": ", solve();
    return 0;
}