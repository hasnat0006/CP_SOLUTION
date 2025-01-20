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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> ans(n + 1);
    if (n % 2) {
        ans[y] = 2;
        ll id = y - 1, f = 0;
        while (id > 0) {
            ans[id--] = f;
            f = !f;
        }
        id = y + 1, f = 1;
        while (id <= n) {
            ans[id++] = f;
            f = !f;
        }
    }
    else {
        ans[y] = 2;
        ll id = y + 1, f = 0;
        while (id <= n) {
            ans[id++] = f;
            f = !f;
        }
        id = y - 1;
        if (id > 0)
            ans[id--] = 1;
        if (id > 0)
            ans[id--] = 0;
        if (id > 0)
            ans[id--] = 2;
        f = 1;
        dbg(ans);
        while (id > 0) {
            ans[id--] = f;
            f = !f;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
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