//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|02|2024 10:56:17            !//
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
    int n, m, k;
    cin >> n >> m >> k;
    int low = 1, high = m, ans = 0;

    auto conSum = [&](int x) { return (x * (x + 1)) / 2; };

    auto isPossible = [&](int mid) {
        int possibleLeft = mid - 1, possibleRight = mid - 1;
        int actualLeft = k - 1, actualRight = n - k;
        int cnt = 0;
        if (actualLeft < possibleLeft)
            cnt += conSum(possibleLeft) - conSum(possibleLeft - actualLeft);
        else
            cnt += conSum(possibleLeft) + actualLeft - possibleLeft;
        if (actualRight < possibleRight)
            cnt += conSum(possibleRight) - conSum(possibleRight - actualRight);
        else
            cnt += conSum(possibleRight) + actualRight - possibleRight;
        cnt += mid;
        return cnt <= m;
    };

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}