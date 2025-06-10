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
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == a[i - 1])
            b[i - 1] = a[i];
        if (b[i] == b[i - 1])
            a[i - 1] = b[i];
    }
    map<ll, ll> A, B;
    for (ll i = 0; i < n; i++) {
        A[a[i]] = i;
        B[b[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (B[a[i]] > i + 1 || B[b[i]] > i + 1 || A[b[i]] > i + 1 ||
            A[a[i]] > i + 1 || a[i] == b[i]) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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