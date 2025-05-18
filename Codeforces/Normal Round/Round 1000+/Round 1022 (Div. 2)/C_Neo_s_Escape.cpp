#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(vr(v));
    vector<ll> vis(n + 3, 0);
    ll ans = 0;
    for (auto [val, idx] : v) {
        if (vis[idx])
            continue;
        if(vis[idx + 1] or vis[idx - 1]) {
            vis[idx] = vis[idx + 1] = vis[idx - 1] = 1;
        }
        else {
            ans++;
            vis[idx] = vis[idx + 1] = vis[idx - 1] = 1;
        }
    }
    cout << ans << endl;
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