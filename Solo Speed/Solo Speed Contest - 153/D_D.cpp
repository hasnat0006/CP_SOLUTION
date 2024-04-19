//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|04|2024 21:31:50            !//
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
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if ((arr[i][j] == 'X' and arr[i][j + 1] == 'X' and
                 arr[i + 1][j] == 'X' and arr[i + 1][j + 1] == '.') or
                (arr[i][j] == 'X' and arr[i][j + 1] == 'X' and
                 arr[i + 1][j] == '.' and arr[i + 1][j + 1] == 'X') or
                (arr[i][j] == 'X' and arr[i][j + 1] == '.' and
                 arr[i + 1][j] == 'X' and arr[i + 1][j + 1] == 'X') or
                (arr[i][j] == '.' and arr[i][j + 1] == 'X' and
                 arr[i + 1][j] == 'X' and arr[i + 1][j + 1] == 'X')) {
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
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}