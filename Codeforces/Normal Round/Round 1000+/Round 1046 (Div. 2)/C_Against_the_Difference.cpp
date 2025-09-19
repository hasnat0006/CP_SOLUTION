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
    vector<ll> v(n);
    vector<ll> adj[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        adj[v[i]].push_back(i);
    }
    vector<ll> ans(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = ans[i + 1];
        ll c = 0;
        if (v[i] == 1)
            c = v[i] + ans[i + 1];
        else {
            auto it = lower_bound(vf(adj[v[i]]), i) - adj[v[i]].begin();
            if (adj[v[i]].size() > it + v[i] - 1) {
                c = v[i];
                c += ans[adj[v[i]][it + v[i] - 1] + 1];
            }
        }
        ans[i] = max(ans[i], c);
    }
    cout << ans[0] << '\n';
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