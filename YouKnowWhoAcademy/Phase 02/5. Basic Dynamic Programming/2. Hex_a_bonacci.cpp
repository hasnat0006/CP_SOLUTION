//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|10|2024 21:43:47            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 10000007;
const ll inf = 1e18;

ll a, b, c, d, e, f, nn;
ll dp[100005];
ll fn(int n) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (n == 2)
        return c;
    if (n == 3)
        return d;
    if (n == 4)
        return e;
    if (n == 5)
        return f;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (fn(n - 1) + fn(n - 2) + fn(n - 3) + fn(n - 4) + fn(n - 5) + fn(n - 6)) % mod;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> a >> b >> c >> d >> e >> f >> nn;
    cout << fn(nn) % mod << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}