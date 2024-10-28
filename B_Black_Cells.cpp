//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|10|2024 21:00:34            !//
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
    for (ll &x : v)
        cin >> x;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    auto findMin = [](vector<ll> temp) {
        ll cnt = 0;
        for (int i = 1; i < temp.size(); i += 2) {
            cnt = max(cnt, temp[i] - temp[i - 1]);
        }
        return cnt;
    };
    if (n % 2 == 0) {
        cout << findMin(v) << '\n';
        return;
    }

    ll ans = inf;
    for (int i = 0; i < n; i++) {
        vector<ll> temp;
        for (int j = 0; j < n; j++) {
            if (j != i)
                temp.push_back(v[j]);
        }
        ans = min(ans, findMin(temp));
    }
    cout << ans << '\n';
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