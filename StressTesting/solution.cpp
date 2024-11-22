//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|11|2024 08:50:54            !//
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];

    while (a.size() and a.back() <= b.back()) {
        a.pop_back();
    }

    b.pop_back();

    if(a.empty()) {
        cout << 0 << '\n';
        return;
    }

    if (b.empty()) {
        if (!a.empty()) {
            cout << -1 << '\n';
        }
        else
            cout << 0 << '\n';
        return;
    }

    n = a.size();
    m = b.size();

    vector<ll> suffix(n);
    partial_sum(vr(a), suffix.rbegin());
    dbg(suffix);

    vector<vector<ll>> dp(m, vector<ll>(n, inf));

    for (ll i = 0, cost = m; i < m; i++, cost--) {
        ll total = 0;
        if (a[n - 1] <= b[i])
            dp[i][n - 1] = cost;
        for (ll j = n - 2; j >= 0; j--) {
            if (suffix[j] - total <= b[i]) {
                dp[i][j] = dp[i][j + 1];
            }
            else if (a[j] <= b[i]) {
                dp[i][j] = dp[i][j + 1] + cost;
                total = suffix[j + 1];
            }
            else
                break;
        }
    }
    dbg(dp);

    if (dp[0][0] == inf) {
        cout << -1 << "\n";
        return;
    }

    vector<ll> cost(m);
    for (ll i = 0, c = m; i < m; i++, c--)
        cost[i] = c;

    dbg(cost);
    ll ans = dp[0][0];

    ll R = 0;
    for (int i = 0; i < m; i++) {
        if (dp[i][0] <= ans) {
            ans = dp[i][0];
            R = i;
        }
    }
    // cout << endl;
    dbg(R);
    ll fixed = ans;
    ll C = 0;
    ll fR = R, fC = 0;
    ll final = 0;
    for (ll col = 1; col < n; col++) {
        dbg("-------------------");
        ll tempAns = ans, tR = R, tC = C;
        dbg(fR, col, fixed);
        //! ager fixed value
        ll check = dp[fR][fC];
        //! current value minus
        check = check - dp[fR][col];
        if (check == 0)
            check += cost[fR];
        dbg("AGE: ", check);
        ll tempFinal = final;
        for (ll row = fR; row < m; row++) {
            dbg(dp[row][col]);
            ll temp = check + dp[row][col];
            dbg(col, row, temp);
            if (temp + final < ans) {
                tempAns = temp;
                tR = row, tC = col;
                tempFinal = ans;
                ans = temp;
                fR = row, fC = tC;
            }
        }
        final = tempFinal;
        dbg("After iteration: ", ans);
    }

    cout << (ans >= inf ? -1 : ans) << '\n';
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