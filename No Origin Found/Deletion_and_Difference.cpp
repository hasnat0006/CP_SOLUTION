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
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        mp[x]++;
    }
    ll len = 0;
    ll ans = 0;
    for (auto [a, b] : mp) {
        if (a == 0)
            len += b;
        else {
            len += (b / 2);
            if (b % 2 != 0)
                ans += 1;
        }
    }
    if (len > 0)
        ans++;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}