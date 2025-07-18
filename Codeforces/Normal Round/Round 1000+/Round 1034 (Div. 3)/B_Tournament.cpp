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
    ll n, j, k, x;
    cin >> n >> j >> k;
    vector<pair<ll, ll>> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        if (i == j)
            x = v[i].first;
    }
    if (k > 1) {
        cout << "YES" << '\n';
        return;
    }
    sort(vr(v));
    if (v.front().first == x)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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