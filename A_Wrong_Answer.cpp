//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|03|2024 18:00:34            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = a + b;
    if (ans == 0)
        ans = 1;
    else if (ans == 9)
        ans = 8;
    else
        ans++;
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