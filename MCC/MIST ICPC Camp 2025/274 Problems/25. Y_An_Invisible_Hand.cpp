#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, t;
    cin >> n >> t;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> pre(n), suf(n);
    pre[0] = v[0], suf[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++)
        pre[i] = min(pre[i - 1], v[i]);
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], v[i]);
    map<ll, ll> mp;
    ll mx = 0;
    mx = max(mx, suf[0] - pre[0]);
    mp[suf[0] - pre[0]]++;
    for (int i = 1; i < n; i++) {
        if (pre[i] != pre[i - 1]) {
            mx = max(mx, suf[i] - pre[i]);
            mp[suf[i] - pre[i]]++;
        }
    }
    cout << mp[mx] << '\n';
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