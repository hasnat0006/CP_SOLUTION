//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 11:55:04            !//
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
    int print, n;
    cin >> print >> n;
    string ans = "";
    while (n != 1) {
        ans.push_back((n % 2) ? 'R' : 'L');
        n /= 2;
    }
    int lob = 1, hor = 1;
    while (ans.size()) {
        if (ans.back() == 'L')
            hor = lob + hor;
        else
            lob = lob + hor;
        ans.pop_back();
    }
    int gcd = __gcd(lob, hor);
    cout << print << " " << lob / gcd << '/' << hor / gcd << endl;
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