//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|08|2024 21:22:46            !//
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
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(vf(a));
    int sum = accumulate(vf(a), 0LL);
    int perServer = sum / n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < perServer)
            ans += perServer - a[i];
    }
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > perServer)
            cnt++;
        else
            break;
    }
    if (cnt >= (sum % n))
        cout << ans << endl;
    else{
        ans = ans + (sum % n) - cnt;
        cout << ans << endl;
    }
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