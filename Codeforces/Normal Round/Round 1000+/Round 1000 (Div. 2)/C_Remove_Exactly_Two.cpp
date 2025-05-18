#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 998244353;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    set<int> adj[n + 1];
    vector<pair<int, int>> degree;
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
        degree.push_back({adj[i].size(), i});
    sort(vr(degree));
    vector<ll> vis(n + 1, 0);
    ll ans = degree[0].first + degree[1].first - 2;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            for (int child : adj[i])
                vis[child] = 1;
            for (auto it : degree) {
                if (!vis[it.second]) {
                    ans = max(ans, (ll)adj[i].size() + it.first - 1);
                    break;
                }
            }
            vis[i] = 0;
            for (int child : adj[i])
                vis[child] = 0;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}