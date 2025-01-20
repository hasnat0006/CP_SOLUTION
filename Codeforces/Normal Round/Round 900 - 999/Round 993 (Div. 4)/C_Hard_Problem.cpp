//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = mod;

void solve() {
    ll m, a, b, c;
    cin >> m >> a >> b >> c;
    ll ans = 0;
    ll r1 = m, r2 = m;
    ll firstRow = min(m, a);
    r1 -= firstRow;
    ans += firstRow;
    ll secRow = min(m, b);
    r2 -= secRow;
    ans += secRow;
    ll addF = min(c, r1);
    ans += addF;
    c -= addF;
    ll addS = min(c, r2);
    ans += addS;
    dbg(firstRow, secRow, addF, addS);
    cout << ans << '\n';
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