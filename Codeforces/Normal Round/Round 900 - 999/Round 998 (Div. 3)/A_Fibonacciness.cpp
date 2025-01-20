#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> v = {a, b, 0, c, d};
    ll ans = 0;
    for (int i = -1000; i <= 1000; i++) {
        v[2] = i;
        ll cnt = 0;
        for (int j = 0; j <= 2; j++) {
            if (v[j + 2] == (v[j] + v[j + 1]))
                cnt++;
        }
        if (cnt != 0)
            dbg(i, v, cnt);
        ans = max(ans, cnt);
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