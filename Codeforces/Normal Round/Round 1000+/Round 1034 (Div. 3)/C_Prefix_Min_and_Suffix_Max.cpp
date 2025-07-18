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
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<ll> pre(n), suf(n);
    pre[0] = v[0];
    for (int i = 1; i < n; i++) {
        pre[i] = min(pre[i - 1], v[i]);
    }
    suf[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], v[i]);
    }
    dbg(pre, suf);
    cout << 1;
    for (int i = 1; i < n - 1; i++) {
        ll l = pre[i - 1], r = suf[i + 1];
        if (v[i] < r and v[i] > l)
            cout << 0;
        else
            cout << 1;
    }
    cout << 1;
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