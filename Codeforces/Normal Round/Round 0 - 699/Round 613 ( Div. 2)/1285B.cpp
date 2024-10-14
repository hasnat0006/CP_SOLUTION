//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|03|2024 02:32:28            !//
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int sum = accumulate(vf(v), 0ll);
    vector<int> prefix(n), suffix(n);
    prefix[0] = v[0], suffix[n - 1] = v.back();
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + v[i];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + v[i];
    int mxPre = *max_element(vf(prefix));
    for (int i = 0; i < n; i++) {
        int tempSum = mxPre - prefix[i];
        if (tempSum >= sum) {
            cout << "NO" << endl;
            return;
        }
    }
    int mxsuf = *max_element(vf(suffix));
    for (int i = n - 1; i >= 0; i--) {
        int tempSum = mxsuf - suffix[i];
        if (tempSum >= sum) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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