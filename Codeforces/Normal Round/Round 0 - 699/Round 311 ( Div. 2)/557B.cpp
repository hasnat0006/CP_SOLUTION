//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|02|2024 21:43:37            !//
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
    float n, cap;
    cin >> n >> cap;
    vector<int> v(2 * n);
    for (int &i : v)
        cin >> i;
    sort(vf(v));

    auto isPossible = [&](float mid) {
        float per = mid / (2 * n + n * 1.0);
        float girl = per;
        float boy = per * 2;
        for (int i = 0; i < n; i++) {
            if (v[i] < girl)
                return false;
        }
        for (int i = n; i < 2 * n; i++) {
            if (v[i] < boy)
                return false;
        }
        return true;
    };

    float low = 0, high = cap, ans = 0;
    while (abs(low - high) > 1e-6) {
        float mid = (low + high) / 2;
        if (isPossible(mid)) {
            ans = mid;
            low = mid;
        }
        else
            high = mid;
    }
    cout << fixed << setprecision(6) << ans << endl;
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