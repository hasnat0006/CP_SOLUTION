//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 02:51:12            !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // todo: Space Optimized;
    vector<int> pre(k + 1, 0), cur(k + 1, 0);
    for (int i = 0; i <= k; i++)
        pre[i] = i % v[0] == 0;
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= k; t++) {
            int notTake = pre[t], take = 0;
            if (t - v[i] >= 0)
                take = cur[t - v[i]];
            cur[t] = (take + notTake) % mod;
        }
        pre = cur;
    }
    cout << pre[k] << endl;
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