#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    if ((n * m) % 3 == 0) {
        cout << 0 << '\n';
        return;
    }
    ll ans = inf;
    ll m1 = m / 2, m2 = m - m1;

    auto calculateDiff = [](ll a1, ll b1, ll a2, ll b2, ll a3, ll b3) {
        return max({a1 * b1, a2 * b2, a3 * b3}) -
               min({a1 * b1, a2 * b2, a3 * b3});
    };

    for (int i = 1; i < n; i++) {
        ll left = i;
        ll right = n - i;
        ans = min({ans, calculateDiff(left, m1, left, m2, right, m),
                   calculateDiff(left, m, right, m1, right, m2)});
    }
    ll n1 = n / 2, n2 = n - n1;
    for (int i = 1; i < m; i++) {
        ll left = i;
        ll right = m - i;
        ans = min({ans, calculateDiff(left, n1, left, n2, right, n),
                   calculateDiff(left, n, right, n1, right, n2)});
    }
    cout << ans << '\n';
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