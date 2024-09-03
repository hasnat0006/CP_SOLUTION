//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|06|2024 21:28:31            !//
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
    int n = 3, k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(vf(v));
    cin >> k;
    vector<int> S;
    for (int i = n - 1; i >= 0; i--) {
        int last = v[i], f = 0;
        for (int j = last - 1; j > 1; j--) {
            if (k % j == 0) {
                S.push_back(j);
                k /= j;
                f = 1;
                break;
            }
        }
        if (f == 0) {
            if (k % last == 0) {
                S.push_back(last);
                k /= last;
            }
            else {
                S.push_back(1);
            }
        }
        // cout << k << endl;
    }
    if (k != 1) {
        cout << 0 << endl;
        return;
    }
    sort(vf(S));
    int ans = 1;
    // for(int i = 0; i < n; i++){
    //     cout << S[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        ans *= (v[i] - S[i] + 1);
    }
    cout << ans << endl;
}

// 2 4 5 8 10 16 17 20 25 32 34 40 50 64 68 80 85 100 125 136 160 170 200 250
// 272 289 320 340 400 425 500 544 578 625 680 800 850 1000 1088 1156 1250 1360
// 1445 1600 1700

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}