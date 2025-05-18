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
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll ans = -inf;
    ll sum = accumulate(vf(v), 0ll);
    ans = max(ans, sum);
    while (v.size() > 1) {
        for (int i = 0; i < v.size() - 1; i++)
            v[i] = (v[i + 1] - v[i]);
        v.pop_back();
        ll tempSum = accumulate(vf(v), 0ll);
        ans = max({ans, tempSum, -tempSum});
    }
    cout << ans << "\n";
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