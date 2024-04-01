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

map<int, vector<pair<int, int>>> adj;
map<int, int> visited, parent, level, color;
set<int> roads;
queue<int> q;

void bfs()
{
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (auto temp : adj[k])
        {
            int child = temp.first;
            int index = temp.second;
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                roads.erase(index);
                // cout << "dukse\n";
            }
        }
    }
}

void solve()
{
    int n, k, d, x, u, v;
    cin >> n >> k >> d;
    for (int i = 0; i < k; i++)
        cin >> x, visited[x] = 1, q.push(x);
    for (int i = 0; i < n - 1; i++)
        cin >> u >> v, adj[u].pb({v, i + 1}), adj[v].pb({u, i + 1});
    for (int i = 1; i < n; i++)
        roads.insert(i);
    bfs();
    cout << roads.size() << endl;
    for (auto i : roads)
        cout << i << " ";
    cout << endl;
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