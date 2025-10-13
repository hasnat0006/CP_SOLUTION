//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|10|2025 11:27:00            !//
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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        pre[i + 1] += (s[i] == 'a' ? 1 : -1);
    }
    if (pre.back() == 0) {
        cout << 0 << '\n';
        return;
    }
    dbg(pre);
    ll needSum = pre.back(), ans = n;
    map<ll, ll> cnt;
    for (int i = 1; i <= n; i++) {
        cnt[needSum + pre[i - 1]] = i;
        if (cnt.count(pre[i])) {
            ans = min(ans, i - cnt[pre[i]] + 1);
        }
        dbg(i, ans, cnt);
    }
    if (ans == n)
        ans = -1;
    cout << ans << '\n';
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