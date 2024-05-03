//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|05|2024 21:04:45            !//
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
    vector<int> a(n), ans(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    ans[0] = 1000;
    // ans[1] = a[1];
    for(int i = 1; i < n; i++)
        ans[i] = ans[i - 1] + a[i];
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    // for(int i = 1; i < n; i++)
    //     cerr << ans[i] % ans[i - 1] << " ";
    // cerr << endl;
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