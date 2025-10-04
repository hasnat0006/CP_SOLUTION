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
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> adj[n + 5];
    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    map<ll, ll> cnt[n + 1];
    vector<ll> mp((int)(2e5 + 5), 0);

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        cnt[u][v[u]]++;
        mp[v[u]]++;
        for (auto c : adj[u]) {
            if (c == p)
                continue;
            dfs(c, u);
            dbg(u, c, cnt[u], cnt[c]);
            for (auto [g, f] : cnt[c]) {
                for (auto [gu, fu] : cnt[u]) {
                    mp[gcd(g, gu)] += (f * fu);
                }
            }
            for (auto [g, f] : cnt[c])
                cnt[u][gcd(v[u], g)] += f;
            cnt[c].clear();
        }
    };

    dfs(1, 0);
    dbg(mp);
    for(int i = 1; i < 2e5 + 5; i++) {
        if(mp[i])
            cout << i << " " << mp[i] << '\n';
    }
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