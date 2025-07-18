#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> clr(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> clr[i];

    vector<ll> adj[n + 5];
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dbg(clr);

    set<ll> colorSet[n + 5];
    vector<ll> ans(n + 5);
    function<void(ll, ll)> dfs = [&](ll node, ll parent) -> void {
        colorSet[node].insert(clr[node]);
        for (auto c : adj[node]) {
            if (c != parent) {
                dfs(c, node);
                if (colorSet[c].size() > colorSet[node].size())
                    swap(colorSet[c], colorSet[node]);
                for (auto i : colorSet[c])
                    colorSet[node].insert(i);
            }
        }
        ans[node] = colorSet[node].size();
        return;
    };

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}