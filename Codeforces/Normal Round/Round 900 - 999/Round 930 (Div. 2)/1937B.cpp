//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|02|2024 21:01:57            !//
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
    string s[2];
    cin >> n >> s[0] >> s[1];
    string ans = "";
    int down = 0;
    for (int i = 0; i < n; i++) {
        if (down == 1) {
            ans += s[1][i];
            continue;
        }
        ans += s[0][i];
        if (i + 1 < n and s[1][i] < s[0][i + 1]) {
            ans += s[1][i];
            down = 1;
        }
    }
    if (down == 0)
        ans += s[1][n - 1];
    cout << ans << endl;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n and s[1][i] == s[0][i + 1])
            cnt++;
        else if (i + 1 < n and s[0][i + 1] == '0' and s[1][i] == '1')
            cnt = 1;
        else 
            break;
    }
    cout << cnt << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}