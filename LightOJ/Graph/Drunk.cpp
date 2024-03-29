//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;
// #include "debug.h"
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

map<string, vector<string>> adj;
map<string, int> color, visited;
bool f = true;

void dfs(string start)
{
    visited[start] = 1;
    for (auto child : adj[start])
    {
        if (visited[child] == 1) // eijaigai visited 1 kina seita always check korte hobe.. 1 howa mane already visited..
            f = false;
        else if (!visited[child])
            (dfs(child));
    }
    //visited ke always 2 korte hobe.... ei 2 na korar jonno amr code mile nai..
    visited[start] = 2;
}

void reset()
{
    f = true, adj.clear(), visited.clear();
}

void solve()
{
    reset();
    int n;
    cin >> n;
    set<string> st;
    while (n--)
    {
        string x, y;
        cin >> x >> y;
        st.insert(x);
        st.insert(y);
        adj[x].pb(y);
    }
    for (auto it : st)
    {
        if (!visited[it])
        {
            dfs(it);
        }
    }
    if (f)
        cout << "Yes\n";
    else
        cout << "No\n";
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