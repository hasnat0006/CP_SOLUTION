//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|11|2024 12:22:06            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

set<ll> ans;
ll actual;

void findAns(int i, string s) {
    if (i < 0) {
        ll four = 0;
        for (auto i : s)
            four += (i == '4');
        ll seven = s.size() - four;
        if (four == seven)
            ans.insert(stoll(s));
        return;
    }
    s[i] = '4';
    findAns(i - 1, s);
    s[i] = '7';
    findAns(i - 1, s);
}

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    actual = stoll(s);
    if (n % 2) {
        s.push_back('0'), n++;
        sort(vf(s));
    }
    findAns(n - 1, s);
    auto it = ans.lower_bound(stoll(s));
    if (it == ans.end()) {
        // cout << "--" << endl;
        ll x = n / 2;
        for (int i = 0; i <= x; i++)
            cout << 4;
        for (int i = 0; i <= x; i++)
            cout << 7;
        return;
    }
    cout << *it << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}