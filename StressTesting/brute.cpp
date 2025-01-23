//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|01|2025 19:17:06            !//
//!-----------------------------------------------------!//

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
    dbg("------------");
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    ll ans = 0;
    for (int i = l; i <= r; i++)
        ans += v[i];
    for (int i = l; i <= r; i++) {
        for (int j = l - 1; j > 0; j--) {
            vector<ll> temp = v;
            dbg(i, j);
            reverse(temp.begin() + j, temp.begin() + i + 1);
            dbg(temp);
            ll tempAns = 0;
            for (int ii = l; ii <= r; ii++)
                tempAns += temp[ii];
            ans = min(ans, tempAns);
            dbg(tempAns);
        }
    }

    for (int i = r; i >= l; i--) {
        for (int j = r + 1; j <= n; j++) {
            vector<ll> temp = v;
            reverse(temp.begin() + i, temp.begin() + j + 1);
            ll tempAns = 0;
            for (int ii = l; ii <= r; ii++)
                tempAns += temp[ii];
            ans = min(ans, tempAns);
            dbg(tempAns);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}