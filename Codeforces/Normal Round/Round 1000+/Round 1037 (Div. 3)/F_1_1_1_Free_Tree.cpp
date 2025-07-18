// heavy light trick

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<int> clr(n);
    for (int i = 0; i < n; i++)
        cin >> clr[i];
    vector<pair<int, int>> adj[n], hadj[n];
    ll ans = 0;

    for (int i = 1; i < n; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        if (clr[u] != clr[v])
            ans += c;
    }

    ll sn = min(n, 70LL);
    vector<bool> v(n, false);
    unordered_map<int, ll> mp[n];

    vector<pair<ll, ll>> sz(n);
    for (int i = 0; i < n; i++)
        sz[i] = {adj[i].size(), i};
    sort(vr(sz));

    for (int i = 0; i < sn; i++) {
        ll u = sz[i].second;
        v[u] = 1;
        for (auto &[v, w] : adj[u]) {
            hadj[v].push_back({u, w});
            mp[u][clr[v]] += w;
        }
    }

    while (q--) {
        ll u, x;
        cin >> u >> x;
        u--;
        if (!v[u]) {
            // light
            for (auto [v, w] : adj[u]) {
                if (clr[u] != clr[v])
                    ans -= w;
                if (clr[v] != x)
                    ans += w;
            }
        }
        else {
            // heavydfgdfg
            ans -= mp[u][x];
            ans += mp[u][clr[u]];
        }
        for (auto &[v, w] : hadj[u]) {
            mp[v][clr[u]] -= w;
            mp[v][x] += w;
            if (mp[v][clr[u]] == 0)
                mp[v].erase(clr[u]);
        }
        clr[u] = x;
        cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}