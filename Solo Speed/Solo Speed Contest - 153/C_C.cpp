//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|04|2024 21:08:00            !//
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int white = 0, red = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        s[i] == 'R' ? red++ : white++;
        if (s[i] == 'W')
            v.push_back(i);
    }
    reverse(v.begin(), v.end());
    int ans = min(white, red);
    int lastWhite = 0;
    for (int i = 0; i < n and i < white; i++) {
        if (s[n - i - 1] == 'W') {
            lastWhite++;
        }
    }
    ans = min(ans, white - lastWhite);
    int firstRed = 0;
    for (int i = 0; i < n and i < red; i++) {
        if (s[i] == 'R') {
            firstRed++;
        }
    }
    ans = min(ans, red - firstRed);
    cout << ans << endl;
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