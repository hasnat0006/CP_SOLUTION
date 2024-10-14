//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|08|2024 11:04:23            !//
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

/*

4
2 3 1          - 1 | 
4 3 5 1 2      - 3 | 2
6 5 4 7 1 2 3  - 3 | 2

*/

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    for (int i = n - 1; i >= n / 2 + 1; i--)
        ans.push_back(i);
    ans.push_back(n);
    for (int i = 1; i <= n / 2; i++)
        ans.push_back(i);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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