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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll ans = 0;
    for (int i = 1; i < n - 1; i += 2) {
        if (v[i - 1] + v[i + 1] <= v[i])
            continue;
        else {
            ll remove = (v[i - 1] + v[i + 1] - v[i]);
            ans += remove;
            v[i + 1] = max(0LL, v[i + 1] - remove);
        }
        dbg(i, ans);
        dbg(v);
    }
    if(n % 2 == 0) {
        ans += max(0LL, v[n - 2] - v[n - 1]);
    }
    cout << ans << '\n';
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