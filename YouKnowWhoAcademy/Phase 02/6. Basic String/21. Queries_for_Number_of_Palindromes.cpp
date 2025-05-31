//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|11|2024 21:08:33            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll int
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

typedef vector<ll> vi;
typedef vector<vi> vii;

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    vii pal(n, vi(n, 0)), dp(n, vi(n, 0));
    for (int i = 0; i < n; i++)
        pal[i][i] = dp[i][i] = 1;
    for (int i = n - 2; i >= 0; i--) {
        vi current(n, 0);
        current[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                if (i + 1 <= j - 1 and pal[i + 1][j - 1] == 1)
                    pal[i][j] = 1;
                if (i + 1 == j)
                    pal[i][j] = 1;
            }
            current[j] = current[j - 1] + pal[i][j];
            dp[i][j] = dp[i + 1][j] + current[j];
        }
    }
    ll q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << dp[l - 1][r - 1] << '\n';
    }
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