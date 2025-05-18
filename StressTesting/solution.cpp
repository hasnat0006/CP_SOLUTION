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
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll cnt = 0;
    while (n > 1 or m > 1) {
        ll x = max(m * (a - 1), m * (n - a));
        ll y = max(n * (b - 1), n * (m - b));
        if (x > y) {
            if (m * (a - 1) > m * (n - a)) {
                n = n - (a - 1);
            }
            else {
                n = n - (n - a);
            }
        }
        else {
            if (n * (b - 1) > n * (m - b)) {
                m = m - (b - 1);
            }
            else {
                m = m - (m - b);
            }
        }
        a = (n + 1) / 2;
        b = (m + 1) / 2;
        cnt++;
        // dbg(n, m, a, b, cnt);
    }
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