//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|11|2024 17:19:45            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
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
    ll n, k, need;
    cin >> n >> k >> need;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<ll> prefix_sum(n), pre(n), suf(n);
    partial_sum(vf(v), prefix_sum.begin());
    ll taste = 0;
    for (ll i = 0; i < n; i++) {
        taste += v[i];
        if (taste >= need) {
            pre[i] = 1 + (i ? pre[i - 1] : 0);
            taste = 0;
        }
        else
            pre[i] = (i ? pre[i - 1] : 0);
    }
    if (pre.back() < k) {
        cout << -1 << '\n';
        return;
    }
    taste = 0;
    for (ll i = n - 1; i >= 0; i--) {
        taste += v[i];
        if (taste >= need) {
            suf[i] = 1 + (i != n - 1 ? suf[i + 1] : 0);
            taste = 0;
        }
        else
            suf[i] = (i != n - 1 ? suf[i + 1] : 0);
    }
    ll ans = 0;
    ll id = lower_bound(vf(pre), k) - pre.begin();
    ans = prefix_sum.back() - prefix_sum[id];
    ll idPre = 0, idSuf = n - 1;
    while (idSuf >= 0 and suf[idSuf] != k) {
        idSuf--;
    }
    ans = max(ans, (idSuf - 1 >= 0 ? prefix_sum[idSuf - 1] : 0));
    for (ll i = 1; i < k; i++) {
        ll left = i, right = k - i;
        while (idPre < n) {
            if (pre[idPre++] == left)
                break;
        }
        while (idSuf < n and suf[idSuf] >= right)
            idSuf++;
        idSuf--;
        if (idSuf >= idPre) {
            ll temp = (idSuf - 1 >= 0 ? prefix_sum[idSuf - 1] : 0) - (idPre - 1 >= 0 ? prefix_sum[idPre - 1] : 0);
            ans = max(ans, temp);
        }
    }
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