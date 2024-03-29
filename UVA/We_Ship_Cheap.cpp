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

map<string, vector<string>> adj;
map<string, int> visited;
map<string, string> parent;
pair<string, string> p;
vector<string> ans;

void bfs(string start)
{
    queue<string> q;
    q.push(start);
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        visited[s] = 1;
        if (s == p.second)
            return;
        for (auto child : adj[s])
        {
            if (!visited[child])
            {
                q.push(child);
                parent[child] = s;
            }
        }
    }
}

void root()
{
    string s = p.second;
    while (s != p.first)
    {
        if (parent[s] == "")
            break;
        ans.pb(s);
        s = parent[s];
    }
}

void reset()
{
    adj.clear();
    parent.clear();
    visited.clear();
    ans.clear();
    p.first = p.second = "";
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    bool f = false;
    while (cin >> t)
    {
        reset();
        if (f)
            cout << endl;
        f = true;
        string a, b;
        for (int i = 0; i < t; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cin >> a >> b;
        p.first = a, p.second = b;
        bfs(p.first);
        root();
        if (ans.size() == 0)
            cout << "No route\n";
        else if (ans[0] != b)
            cout << "No route\n";
        else
        {
            reverse(vf(ans));
            for (auto it : ans)
            {
                cout << parent[it] << " " << it << endl;
            }
        }
    }
    return 0;
}