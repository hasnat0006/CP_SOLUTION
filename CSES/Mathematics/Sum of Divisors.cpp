//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|04|2024 00:05:58            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    auto findSum = [](int l, int r){
        l %= mod;
        r %= mod;
        int left = (l * (l + 1)) / 2;
        int right = (r * (r + 1)) / 2;
        left %= mod;
        right %= mod;
        return (right - left + mod) % mod;
    };
    for (int i = 1; i * i <= n; i++) {
        int numberofTimes = n / i;
        numberofTimes %= mod;
        ans += (((numberofTimes - i + mod + 1) % mod) * i) % mod;
        ans %= mod;
        ans += findSum(i, numberofTimes);
        ans %= mod;
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