//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|03|2024 21:10:09            !//
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
    int n = s.size();
    int start = 0, cnt = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[0] or s[i] == s[n - 1]) {
            start = 0;
            continue;
        }
        else {
            start++;
        }
        cnt = max(cnt, start);
    }
    cout << (cnt == 0 ? -1 : cnt) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    ;
    ;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}