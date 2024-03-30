//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|03|2024 21:09:32            !//
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
    string s;
    cin >> s;
    int x;
    cin >> x;

    auto shift_lower = [&](char c, int x) {
        return (c - 'a' + x) % 26 + 'a';
    };

    auto shift_upper = [&](char c, int x) {
        return (c - 'A' + x) % 26 + 'A';
    };

    for(int i = 0; i < n; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = shift_lower(s[i], x);
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = shift_upper(s[i], x);
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