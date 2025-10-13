//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|10|2025 07:26:56            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    auto to_bin = [](ll n) {
        string s;
        while (n) {
            if (n & 1)
                s.push_back('1');
            else
                s.push_back('0');
            n /= 2;
        }
        return s;
    };

    auto is_valid = [](string &s) {
        ll n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != s[n - 1 - i])
                return false;
        }
        if (n % 2 and s[n / 2] == '1')
            return false;
        return true;
    };

    string s = to_bin(n);
    for (int i = 0; i < 40; i++) {
        if (is_valid(s)) {
            cout << "YES\n";
            return;
        }
        s.push_back('0');
    }
    cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}