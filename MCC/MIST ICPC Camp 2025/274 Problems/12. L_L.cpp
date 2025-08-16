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
    double a, b, c;
    cin >> a >> b >> c;
    c *= acos(-1.0);
    dbg(a, b, c);
    auto cal = [&](double t) { return a * t + b * sin(c * t); };

    double l = floor(100.0 / a), r = ceil(100.0 / a);
    for (int i = 100; i > 0; i--) {
        double mid = (l + r) / 2.0;
        if (cal(mid) < 100.0)
            l = mid;
        else
            r = mid;
        dbg(l);
    }
    cout << fixed << setprecision(10) << l << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}