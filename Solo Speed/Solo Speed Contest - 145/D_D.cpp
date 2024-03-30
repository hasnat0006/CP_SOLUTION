//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|02|2024 21:32:01            !//
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
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 0 or k == n * m) {
        cout << "Yes" << endl;
        return;
    }
    /*
        Explanation:
        i * m is the number of squares in the rectangle if we have i rows and m columns.
        j * n is the number of squares in the rectangle if we have j rows and n columns.
        2 * i * j is the number of squares that are counted twice in i * m and j * n.
    */
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i * m + j * n - 2 * i * j == k) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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