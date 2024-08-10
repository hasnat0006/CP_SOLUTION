//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|07|2024 22:48:57            !//
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

*/

void solve() {
    for (int cnt1 = 0; cnt1 < 26; cnt1++) {
        for (int cnt2 = 0; cnt2 < 26; cnt2++) {
            for (int cnt3 = 0; cnt3 < 26; cnt3++){
                for (int cnt4 = 0; cnt4 < 26; cnt4++){
                    cout << (char)('a' + cnt1) << (char)('a' + cnt2)
                         << (char)('a' + cnt3) << (char)('a' + cnt4) << "2368"<< endl;
                }
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("output.txt", "w", stdout);
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}