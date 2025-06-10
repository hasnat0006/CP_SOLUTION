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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll y = (a[0] * 2 - a[1]) / (n + 1);
    ll x = a[1] - a[0] + y;
    if (y < 0 || x < 0) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        a[i] -= ((x * (i + 1)) + (y * (n - i)));
        if (a[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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