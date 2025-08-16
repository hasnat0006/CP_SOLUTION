#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
const ll mod = 998244353;
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
ll mminvprime(ll a, ll b) { return binaryExp(a, b - 2, b); }
ll mod_mul(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}
ll mod_sub(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a - b) % MOD) + MOD) % MOD;
}
ll mod_add(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}

ll mod_div(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (mod_mul(a, mminvprime(b, MOD), MOD) + MOD) % MOD;
}  // only for prime MOD

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> segments[m + 5];
    ll howa = 1, nahowa = 1;
    for (ll i = 0; i < m; i++) {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        ll pp = mod_div(p, q);
        ll qq = mod_sub(1, pp);
        howa = mod_mul(howa, pp);
        nahowa = mod_mul(nahowa, qq);
        segments[l].push_back(make_tuple(r, pp, qq));
    }
    dbg(howa, nahowa);

    function<pair<ll, ll>(ll)> calAns = [&](ll x) -> pair<ll, ll> {
        if (x == m + 1)
            return {1, 1};
        ll ans = 1, nahowa = 1;
        for (auto [r, p, q] : segments[x]) {
            auto [ans, nah] = calAns(r + 1);
            howa =  mod_mul(p, ans);
            nahowa =  mod_mul(q, nah);
        }
        return {howa, nahowa};
    };

    auto [ans, nah] = calAns(1);
    dbg(ans, nah);
    cout << mod_mul(ans, mod_div(nahowa, nah)) << '\n';
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