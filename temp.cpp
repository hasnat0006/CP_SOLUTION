//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|09|2024 02:41:13            !//
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
    int n, k;
    cin >> n >> k;

    auto rangeSum = [&](int l, int r) {
        return (r * (r + 1) / 2) - (l * (l - 1) / 2);
    };

    int low = k, high = k + n - 1, ans = inf;
    while (low <= high) {
        int mid = (low + high) / 2;
        int sum1 = rangeSum(k, mid);
        int sum2 = rangeSum(mid + 1, k + n - 1);
        ans = min(ans, abs(sum1 - sum2));
        if (sum1 > sum2)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}