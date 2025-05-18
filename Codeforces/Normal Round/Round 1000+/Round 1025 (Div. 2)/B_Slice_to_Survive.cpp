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
    a = min(a, n - a + 1);
    b = min(b, m - b + 1);
    auto findAns = [] (ll n, ll m) {
        ll c = 0;
        while(n > 1)
            c++, n = (n + 1) / 2;
        while(m > 1)
            c++, m = (m + 1) / 2;
        return c;
    };
    cout << min(findAns(n, b), findAns(a, m)) + 1 << endl;
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