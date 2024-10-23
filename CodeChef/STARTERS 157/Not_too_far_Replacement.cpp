//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|10|2024 20:34:33            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;
    ll last;
    cin >> last;
    sort(vf(v));
    while (n--) {
        int id = upper_bound(vf(v), last * 2) - v.begin() - 1;
        if (id == -1)
            break;
        if (v[id] > last)
            swap(v[id], last);
    }
    int sum = accumulate(vf(v), 0ll);
    cout << sum << '\n';
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