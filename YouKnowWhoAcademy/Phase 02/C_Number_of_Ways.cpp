//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|10|2024 23:06:13            !//
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

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<int> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll sum = accumulate(vf(v), 0LL);
    if (sum % 3 != 0) {
        cout << 0 << '\n';
        return;
    }
    ll need = sum / 3;
    dbg(sum, need);
    ll sum_till_i = 0;
    if (need == 0) {
        int cnt = 0;
        for (ll i = 0; i < n; i++) {
            sum_till_i += v[i];
            if (sum_till_i == 0)
                cnt++;
        }
        vector<ll> ans(cnt + 1, 0);
        for (int i = 3; i <= cnt; i++) {
            ans[i] = i - 2 + ans[i - 1];
        }
        cout << ans[cnt] << '\n';
        return;
    }
    map<ll, ll> mp;
    int idLeft = -1, idRight = -1;
    for (ll i = 0; i < n; i++) {
        sum_till_i += v[i];
        if (sum_till_i == need) {
            idLeft = i + 1;
            break;
        }
    }
    sum_till_i = 0;
    for (ll i = n - 1; i >= 0; i--) {
        sum_till_i += v[i];
        if (sum_till_i == need) {
            idRight = i - 1;
            break;
        }
    }
    ll ans = 0;
    sum_till_i = 0;
    for (ll i = idLeft; i <= idRight; i++) {
        sum_till_i += v[i];
        if (sum_till_i % need == 0)
            ans++;
    }
    dbg(ans);
    cout << (ans * (ans - 1)) / 2LL << '\n';
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