//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|06|2024 22:24:53            !//
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
    int n, gcd;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    vector<int> prefixGcd(n + 1), suffixGcd(n + 1);
    prefixGcd[0] = 0;
    suffixGcd[n] = 0;
    for (int i = 1; i <= n; i++)
        prefixGcd[i] = __gcd(prefixGcd[i - 1], v[i - 1]);
    for (int i = n - 1; i >= 0; i--)
        suffixGcd[i] = __gcd(suffixGcd[i + 1], v[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        gcd = __gcd(prefixGcd[i - 1], suffixGcd[i]);
        ans = max(ans, gcd);
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