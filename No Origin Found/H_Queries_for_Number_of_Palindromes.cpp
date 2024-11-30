//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|11|2024 21:08:33            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

    vii pal(n, vi(n, 0)), prefix(n, vi(n, 0)), dp(n, vi(n, 0));

    auto printing = [&](vii a) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
        return;
    };

    for (int i = 0; i < n; i++)
        pal[i][i] = prefix[i][i] = dp[i][i] = 1;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // s[i...j] is a palindrome or not
            if (s[i] == s[j]) {
                if (i + 1 <= j - 1 and s[i + 1] == s[j - 1])
                    pal[i][j] = 1;
                if (i + 1 == j)
                    pal[i][j] = 1;
            }
            prefix[i][j] = prefix[i][j - 1] + pal[i][j];
            dp[i][j] = dp[i + 1][j] + prefix[i][j];
        }
    }
    ll q;
    cin >> q;
    while(q--) {
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