//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|03|2024 03:42:36            !//
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
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            if (i != n - 1) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (s[i - 1] != c and s[i + 1] != c) {
                        s[i] = c;
                        break;
                    }
                }
            }
            else
                for (char c = 'a'; c <= 'z'; c++) {
                    if (s[i - 1] != c and s[i + 1] != c) {
                        s[i] = c;
                        break;
                    }
                }
        }
    }
    cout << s << endl;
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