#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 998244353;
const ll inf = 1e18;

ll mod_add(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
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
ll mod_mul(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}
ll mod_div(ll a, ll b, ll MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (mod_mul(a, mminvprime(b, MOD), MOD) + MOD) % MOD;
}  // only for prime MOD

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll mx = *max_element(vf(v));
    ll N = mx + 5;
    vector<ll> dp(N), cnt(N);
    vector<ll> freq(N), f(N), s(N);

    for (int i = 0; i < n; i++)
        freq[v[i]]++;

    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            f[i] += freq[j] * j;
        }
    }
    for (int i = mx; i > 0; i--) {
        dp[i] = mod_mul(f[i], f[i]);
        for (int j = 2 * i; j <= mx; j += i) {
            dp[i] -= dp[j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= mx; i++)
        ans = mod_add(ans, mod_div(dp[i], i));
    for(int i = 0; i < n; i++) {
        ans = mod_add(ans, -v[i]);
    }
    cout << mod_div(ans, 2) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // freopen("lcm.in", "r", stdin);
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}