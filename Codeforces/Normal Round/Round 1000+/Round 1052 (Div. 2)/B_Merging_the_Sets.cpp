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

    set<ll> adj[m + 5];
    vector<ll> v[n + 1];
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        vector<ll> temp;
        for (int j = 0; j < x; j++) {
            ll val;
            cin >> val;
            adj[val].insert(i + 1);
            temp.push_back(val);
        }
        v[i] = temp;
    }

    for (int i = 1; i <= m; i++) {
        if (adj[i].size() == 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    auto is_possible = [&](ll id) {
        for (int i = 0; i < v[id].size(); i++) {
            if (adj[v[id][i]].size() == 1)
                return false;
        }
        return true;
    };
    ll c = 0;
    for (int i = 0; i < n; i++) {
        if (is_possible(i))
            c++;
    }
    cout << (c >= 2 ? "YES" : "NO") << '\n';
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