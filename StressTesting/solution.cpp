//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|04|2024 11:22:40            !//
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
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    /*
    Case 1: pasapasi 2 ta col e diagonaillay same ase kina..
    abcd
    bcff
    eikhane b and c diagonally same
    */
    for (int row = 0; row < n - 1; row++) {
        for (int j = 1; j < m - 1; j++) {
            if (arr[row][j] == arr[row + 1][j - 1] and
                arr[row][j + 1] == arr[row + 1][j]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    /*
    Case 2: uporeniche 2 ta row e diagonaillay same ase kina..
    ab
    bc
    cf
    df
    eikhane b and c diagonally same
    */
    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == arr[i + 1][j - 1] and
                arr[i + 1][j] == arr[i + 2][j - 1]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    /*
    Case 3: ektar right e arekta diagonally same ase kina..
    abdd
    bccf
    xxfb
    eikhane b diagonally same and tar right e f diagonally same
    */
    int i, j, f = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < m; j++) {
            if (arr[i][j] == arr[i + 1][j - 1]) {
                f = 1;
                break;
            }
        }
        if (f)
            break;
    }
    if (f) {
        for (int row = i + 1; row < n - 1; row++) {
            for (int col = j + 1; col < m; col++) {
                if (arr[row][col] == arr[row + 1][col - 1]) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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