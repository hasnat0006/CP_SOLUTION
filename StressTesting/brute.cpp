//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|04|2024 10:31:39            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        if (n == 1)
            n = 0;
        if (n % 2)
            n++;
        n /= 2;
        ans++;
        // cout << n << " " << ans << endl;
    }
    cout << ans << endl;
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