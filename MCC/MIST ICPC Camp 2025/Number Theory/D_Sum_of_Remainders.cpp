#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll mod_add(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}
ll mod_mul(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}
ll mod_sub(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a - b) % MOD) + MOD) % MOD;
}

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
ll mminvprime(ll a, ll b) { return binaryExp(a, b - 2, b); }

ll mod_div(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (mod_mul(a, mminvprime(b, MOD), MOD) + MOD) % MOD;
}  // only for prime MOD

ll range_sum(ll l, ll r) {
    ll a = mod_div(mod_mul(l, l - 1), 2);
    ll b = mod_div(mod_mul(r, r + 1), 2);
    return mod_sub(b, a);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0, pre = sqrt(n);
    vector<pair<ll, ll>> s;
    for (ll i = min(pre, m); i >= 1; i--) {
        s.push_back({n / i, i});
        ans = mod_add(ans, mod_mul((n / i), i));
    }
    ll start = pre + 1;
    for (auto [val, i] : s) {
        if(start > m) break;
        ll total = val - pre;
        ll end = start + total - 1;
        end = min(end, m);

        ll sum = range_sum(start, end);
        sum = mod_mul(sum, (n / val));
        ans = mod_add(ans, sum);
        pre = val;
        start = end + 1;
        if(end == m) break;
    }
    ans = mod_sub(mod_mul(n, m), ans);
    cout << ans << "\n";
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