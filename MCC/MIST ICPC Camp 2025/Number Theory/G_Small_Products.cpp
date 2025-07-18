#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll int
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    unordered_map<ll, unordered_map<ll, ll>> dp;
    unordered_map<ll, ll> pref;
    for (int i = 1, next; i <= n; i = next) {
        next = n / (n / i) + 1;
        pref[next - 1] = ((1LL * pref[i - 1]) + (next - i)) % mod;
    }
    for (int i = k - 1; i >= 0; i--) {
        for (int j = 1, next; j <= n; j = next) {
            next = n / (n / j) + 1;
            dp[i][j] = pref[n / j];
            dp[i][j] %= mod;
        }
        for (int j = 1, next; j <= n; j = next) {
            next = n / (n / j) + 1;
            pref[next - 1] = (1LL * pref[j - 1]) + (1LL * dp[i][j] * (next - j)) % mod;
            pref[next - 1] %= mod;
        }
    }
    cout << dp[0][1] << "\n";
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