//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|04|2024 18:17:11            !//
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
    string s, t;
    cin >> s >> t;
    if (t.back() == 'X')
        t.pop_back();
    int n = s.size(), m = t.size();
    transform(t.begin(), t.end(), t.begin(), ::tolower);
    int length = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == t[j]) {
            j++;
            length++;
        }
        if(j == m)
            break;
    }
    if (length == m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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