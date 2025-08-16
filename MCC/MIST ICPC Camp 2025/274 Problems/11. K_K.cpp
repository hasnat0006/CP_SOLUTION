#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, inf));
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    vector<ll> v(n + 1, inf);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
        if (a == 1)
            v[b] = c;
        else
            dp[a][b] = dp[b][a] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ll ans = inf;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            ans = min(ans, dp[i][j] + v[i] + v[j]);
        }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
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