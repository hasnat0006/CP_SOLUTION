//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
//#include "debug.h"
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
map<int, int> color;
bool f = true;

void initial()
{
    adj.clear();
    visited.clear();
    level.clear();
    parent.clear();
    color.clear();
    f = true;
}

void dfs(int start)
{
    visited[start] = 1;
    if (!color[start])
        color[start] = 1;
    for (auto child : adj[start])
    {
        if (!visited[child])
        {
            parent[child] = start;
            if (color[start] == 1)
                color[child] = 2;
            else
                color[child] = 1;
            dfs(child);
        }
        else
        {
            if (color[child] == color[start])
                f = false;
        }
    }
}

void solve()
{
    initial();
    int n, m;
    cin >> n >> m;
    set<int> st;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        st.insert(x);
        st.insert(y);
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (auto i : st)
    {
        if (!visited[i])
        {
            dfs(i);
            if (!f)
            {
                cout << "Suspicious bugs found!\n";
                return;
            }
        }
    }
    cout << "No suspicious bugs found!\n";
    // debug(color);
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << "Scenario #" << i + 1 << ":\n", solve();
    return 0;
}