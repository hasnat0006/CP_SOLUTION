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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(vf(b));
    ll last = (b[0] - a[0] <= a[0]) ? b[0] - a[0] : a[0];
    a[0] = last;
    for (int i = 1; i < n; i++) {
        ll id = lower_bound(vf(b), a[i - 1] + a[i]) - b.begin();
        ll temp = a[i];
        if (id < m)
            temp = (b[id] - a[i]);
        if (a[i] >= a[i - 1])
            temp = min(a[i], temp);
        a[i] = temp;
    }
    cout << (is_sorted(vf(a)) ? "YES" : "NO") << '\n';
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