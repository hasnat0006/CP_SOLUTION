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
    ll x;
    cin >> x;
    vector<ll> v(3, 0);
    ll cur = 0, i = 0, cnt = 0;
    while (cur <= x) {
        v[i] = min(v[(i + 1) % 3], v[(i + 2) % 3]) * 2 + 1;
        cur = v[i];
        i = (i + 1) % 3;
        cnt++;
    }
    for (auto i : v)
        if (i < x)
            cnt++;
    cout << cnt << endl;
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