//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|02|2024 14:05:50            !//
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

int n, k;
vector<int> need, have;

void solve() {
    cin >> n >> k;
    need.resize(n);
    have.resize(n);
    for (int &i : need)
        cin >> i;
    int low = 0, high = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> have[i];
        high = max(high, (have[i] + k) / need[i] + 1);
    }

    auto isPossible = [&](int mid) {
        int usedK = 0;
        for (int i = 0; i < n; i++) {
            if (need[i] * mid > have[i])
                usedK += need[i] * mid - have[i];
            if (usedK > k)
                return false;
        }
        return true;
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