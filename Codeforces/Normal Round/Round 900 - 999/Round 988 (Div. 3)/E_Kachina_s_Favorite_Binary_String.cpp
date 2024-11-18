//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|11|2024 00:14:11            !//
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

    auto ask = [](ll l, ll r) {
        cout << "? " << l << " " << r << endl;
        ll x;
        cin >> x;
        return x;
    };
    
    string ans = "";
    ll r = 2, last = 0;
    while (r <= n) {
        ll query = ask(1, r);
        last = query;
        if (query) {
            int temp = r - 1 - query;
            while (temp--)
                ans.push_back('1');
            while (query--)
                ans.push_back('0');
            ans.push_back('1');
            r++;
            break;
        }
        r++;
    }
    while (r <= n) {
        ll query = ask(1, r);
        if (query == last)
            ans.push_back('0');
        else
            ans.push_back('1');
        r++;
        last = query;
    }
    if (ans.size() == n)
        cout << "! " << ans << endl;
    else
        cout << "! IMPOSSIBLE" << endl;
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