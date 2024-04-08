//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 22:12:17            !//
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
    int n, c, d;
    cin >> n >> c >> d;
    int a[n][n];
    vector<int> b(n * n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n * n; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    int mn = *min_element(vf(b));
    a[0][0] = mn;
    for (int i = 1; i < n; i++) {
        a[0][i] = a[0][i - 1] + c;
    }
    for (int i = 1; i < n; i++) {
        a[i][0] = a[i - 1][0] + d;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            a[i][j] = max(a[i - 1][j] + d, a[i][j - 1] + c);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[a[i][j]])
                mp[a[i][j]]--;
            else {
                cout << "NO" << endl;
                return;
            }
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