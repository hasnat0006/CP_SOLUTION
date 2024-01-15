//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

vector<int> adj[100005];
vector<int> visited(100005, 0), add(100005), rem(100005);
unordered_map<int, int> GCD;

void dfs(int start, int x) {
    visited[start] = 1;
    GCD[start] = __gcd(add[start], x);
    for (auto child : adj[start])
        if (!visited[child])
            dfs(child, GCD[start]);
    visited[start] = 2;
}

void solve() {
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        adj[x].pb(y);
    }
    for (int i = 1; i <= n; i++)
        cin >> add[i];
    for (int i = 1; i <= n; i++)
        cin >> rem[i];
    dfs(1, add[1]);
    dbg(GCD);
    for (int i = 1; i <= n; i++) {
        if (!adj[i].size()) {
            GCD[i] = __gcd(GCD[i], rem[i]);
            cout << rem[i] - GCD[i] << " ";
        }
    }
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}