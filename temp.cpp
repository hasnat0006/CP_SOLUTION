//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|10|2024 23:22:01            !//
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
    vector<pair<float, float>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    // int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1].second <= v[i].first) {
            cout << -1ll << endl;
            return;
        }
    }
    float low = 0, high = n, ans = 0;
    for (int i = 0; i < n; i++) {
        float time1 = 0;
        if (v[i].first == 0)
            time1 = n;
        else
            time1 = ((float)i + 1) / v[i].first;
        float time2 = ((float)i + 1) / v[i].second;
        low = min({low, time1, time2});
        high = max({low, time1, time2});
    }
    low -= 0.5, high += 0.5;
    while (high - low > 1e-6) {
        float mid = (low + high) / 2;
        int f = 0;
        for (int i = 0; i < n; i++) {
            float time = ((float)i + 1) / mid;
            if (time >= v[i].first and time <= v[i].second) {
                continue;
            }
            else if (time < v[i].first) {
                // time komaite hobe
                f = 1;
            }
            else {
                // time baraite hobe
                f = 2;
            }
        }
        if (f == 1) {
            high = mid;
        }
        else if (f == 2) {
            low = mid;
        }
        else {
            high = mid;
            ans = mid;
        }
    }
    cout << fixed << setprecision(6) << high << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}