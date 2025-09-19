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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    // check first half
    ll mn = min(a, b), mx = max(a, b);
    mx -= 2;
    if (mx / 2 + (mx % 2) > mn) {
        cout << "NO" << '\n';
        return;
    }

    // ll d1 = (a / c + (a % c != 0)), d2 = (b / d + (b % d != 0));
    // c = c * max(d1, d2), d = d * max(d1, d2);
    dbg(a, b, c, d);

    mn = min(c - a, d - b), mx = max(c - a, d - b);
    dbg(mn, mx);
    mx -= 2;
    if (mx / 2 + (mx % 2) > mn) 
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
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