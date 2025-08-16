#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 5];
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    function<void(set<ll>, ll)> dfs = [&](set<ll> s, ll pre) {
        if (s.size() == n)
            ans++;
        for (auto v : adj[pre]) {
            if (s.find(v) == s.end()) {
                s.insert(v);
                dfs(s, v);
                s.erase(v);
            }
        }
    };
    dfs({1}, 1);
    cout << ans << '\n';
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