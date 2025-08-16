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
    ll n, m;
    cin >> n >> m;
    vector<bitset<15>> adj(n + 5);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = adj[u][u] = adj[v][v] = 1;
    }

    set<vector<ll>> st;
    function<void(ll, vector<ll>)> findAns = [&](ll i, vector<ll> v = {}) {
        if (i == 0) {
            st.insert(v);
            return;
        }
        dbg(i, v);
        findAns(i - 1, v);
        v.push_back(i);
        findAns(i - 1, v);
        v.pop_back();
        return;
    };

    findAns(n, {});
    ll ans = 1;
    dbg(st);
    for (auto &v : st) {
        ll f = 0;
        for (auto it : v) {
            for (int i : v) {
                if (!adj[it][i]) {
                    f = 1;
                    break;
                }
            }
            if (f)
                break;
        }
        if (!f)
            ans = max(ans, (ll)v.size());
    }
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