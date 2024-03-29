//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 20:48:08            !//
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
    int nn = n * 2;
    char arr[nn][nn];
    int f = 1;
    char dot[2][2] = {{'.', '.'}, {'.', '.'}};
    char hash[2][2] = {{'#', '#'}, {'#', '#'}};
    for (int cnt = 0, i = 0; cnt < n; cnt++, i += 2) {
        if (cnt % 2) {
            arr[0][i] = dot[0][cnt % 2];
            arr[1][i] = dot[0][cnt % 2];
            arr[0][i + 1] = dot[0][cnt % 2];
            arr[1][i + 1] = dot[0][cnt % 2];
        }
        else {
            arr[0][i] = hash[0][cnt % 2];
            arr[1][i] = hash[0][cnt % 2];
            arr[0][i + 1] = hash[0][cnt % 2];
            arr[1][i + 1] = hash[0][cnt % 2];
        }
    }
    char arr2[nn][nn];
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < nn; j++) {
            arr2[i][j] =(arr[i][j] == '#') ? '.' : '#';
        }
    }
    for (int cnt = 0; cnt < n; cnt++) {
        if (cnt % 2) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < nn; j++) {
                    cout << arr2[i][j];
                }
                cout << endl;
            }
        }
        else {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < nn; j++) {
                    cout << arr[i][j];
                }
                cout << endl;
            }
        }
        // cout << endl;
    }
    // cout << endl;
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