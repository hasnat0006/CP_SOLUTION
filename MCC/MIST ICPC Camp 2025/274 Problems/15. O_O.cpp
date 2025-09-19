#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, a;
    string k;
    cin >> n >> a >> k;
    vector<ll> adj[n + 5];
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        adj[i].push_back(x);
    }
    vector<ll> vis(n + 5, 0), depth(n + 5, -1);
    auto digitMod = [&](ll m) {
        ll x = 0;
        ll p = 1;
        for (int i = k.size() - 1; i >= 0; i--) {
            if ((x += p * (k[i] - '0') % m) >= m)
                x -= m;
            p = p * 10 % m;
        }
        return x;
    };

    ll pos = a;
    depth[pos] = 0;
    vector<ll> store;
    while (!vis[pos]) {
        store.push_back(pos);
        vis[pos] = 1;
        if (depth[adj[pos].front()] == -1)
            depth[adj[pos].front()] = depth[pos] + 1;
        pos = adj[pos].front();
    }
    ll cycleLength = *max_element(vf(depth)) - depth[pos] + 1;
    ll withoutCycle = *max_element(vf(depth)) - cycleLength + 1;
    ll rem =
        ((digitMod(cycleLength) - (withoutCycle % cycleLength)) + cycleLength) %
        cycleLength;
    if (k <= to_string(withoutCycle) and k.size() < 16 and
        stoll(k) < store.size())
        cout << store[stoll(k)] << '\n';
    else
        cout << store[withoutCycle + rem] << '\n';
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
