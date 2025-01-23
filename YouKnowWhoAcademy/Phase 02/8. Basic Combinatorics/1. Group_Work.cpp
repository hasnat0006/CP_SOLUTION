//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|01|2025 12:11:14            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

__int128_t nFact(ll n) {
    __int128_t ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += (nFact(n) / (nFact(n - i) * (nFact(i))));
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}