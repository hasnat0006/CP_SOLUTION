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

map<char, set<char>> adj;
map<char, int> visited, level;
int k = 0;
string ans;

void dfs(char start)
{
    visited[start] = 1;
    level[start] = k++;
    ans.pb(start);
    for (auto child : adj[start])
        if (!visited[child])
            dfs(child);
}

void reset()
{
    adj.clear(), visited.clear(), level.clear(), ans.clear(), k = 0;
}

void solve()
{
    reset();
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
        adj[s[i]].insert(s[i - 1]), adj[s[i - 1]].insert(s[i]);
    // debug(adj);
    for (char i = 'a'; i <= 'z'; i++)
        if (!visited[i] and adj[i].size() <= 1)
            dfs(i);
    int check = 0;
    for (int i = 1; i < s.size(); i++)
        if (abs(level[s[i]] - level[s[i - 1]]) != 1)
            check = 1;
    if (check)
        cout << "NO\n";
    else
        cout << "YES\n", cout << ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}