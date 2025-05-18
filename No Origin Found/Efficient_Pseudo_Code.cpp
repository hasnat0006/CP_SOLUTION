#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll binaryExp(ll base, ll power, ll MOD = mod) {
    ll res = 1;
    while (power) {
        if (power & 1)
            res = (res * base) % MOD;
        base = ((base % MOD) * (base % MOD)) % MOD;
        power /= 2;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;

    auto factor = [](ll n) -> ll {
        if (n % 2 == 0)
            return 2;
        for (ll a = 3; a * a <= n; a++) {
            if (n % a == 0)
                return a;
        }
        return n;
    };
    while (n > 1) {7890
        ll r = factor(n);
        while (n % r == 0) {
            mp[r]++;
            n /= r;
        }
    }
    ll ans = 1;
    for (auto &[a, b] : mp) {
        b *= m;
        ans *= binaryExp(a, b + 1) - 1;
        ans %= mod;
        ans *= binaryExp(a - 1, mod - 2);
        ans %= mod;
    }
    cout << ((ans + mod) % mod) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}