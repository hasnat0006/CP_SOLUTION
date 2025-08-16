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
    vector<bitset<15>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = adj[v][v] = adj[u][u] = 1;
    }
    // dbg(adj);
    for (auto i : adj)
        dbg(i);
    ll ans = 1;
    map<ll, ll> mp;
    for (int here = 1; here <= n; here++) {
        set<ll> st;
        for (int i = 0; i < 15; i++)
            if (adj[here][i])
                st.insert(i);
        vector<ll> t;
        ll mn = inf;
        for (auto val : st) {
            set<ll> temp = st;
            ll c = 0;
            for (int i = 0; i < 15; i++) {
                if (temp.find(i) != temp.end() and adj[val][i]) {
                    temp.erase(i);
                    c++;
                }
            }
            mn = min(mn, c);
            t.push_back(c);
        }
        mp[mn]++;
        sort(vf(t));
        dbg(here, mn, st, t);
    }
    for(auto [i, c] : mp)
        if(c >= i)
            ans = max(ans, i);
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