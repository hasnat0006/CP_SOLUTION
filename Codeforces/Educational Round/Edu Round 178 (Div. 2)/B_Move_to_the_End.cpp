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
    ll n;
    cin >> n;
    vector<ll> a(n), mx(n, 0);
    ll mmx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mmx = max(mmx, a[i]);
        mx[i] = mmx;
    }
    vector<ll> suf(n, 0);
    partial_sum(a.rbegin(), a.rend(), suf.rbegin());
    dbg(suf);
    cout << mmx << " ";
    for(int i = n - 2; i >= 0; i--) {
        ll temp = mx[i];
        cout << max(suf[i + 1] + temp, suf[i]) << " ";
    }
    cout << "\n";
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