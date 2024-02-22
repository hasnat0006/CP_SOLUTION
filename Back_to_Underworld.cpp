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
map<int, int> visited, color, level;

bool dfs(int start, int clr) {
    color[start] = clr, visited[start] = 1;
    for (auto child : adj[start]) {
        if (!visited[child]) {
            dfs(child, clr ^ 1);
        }
    }
}

void reset() { adj.clear(), color.clear(), visited.clear(), level.clear(); }

void solve() {
    reset();
    int n, x, y;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        st.insert(x);
        st.insert(y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (auto it : st)
        if (!visited[it])
            dfs(it, 0);
    int red = 0, green = 0;
    for (auto it : color) {
        if (it.second)
            green++;
        else
            red++;
    }
    cout << max(red, green) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case " << i << ": ", solve();
    return 0;
}