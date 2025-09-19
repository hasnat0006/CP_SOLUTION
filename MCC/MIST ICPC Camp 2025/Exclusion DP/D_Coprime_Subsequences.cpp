#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
const ll mod = 1e9 + 7;
const ll inf = 1e18;

const ll MAX = 1e6 + 5;
vector<ll> fact(MAX), ifact(MAX), inv(MAX);

void factorial() {
    inv[1] = fact[0] = ifact[0] = 1;
    for (ll i = 2; i < MAX; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for (ll i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    for (ll i = 1; i < MAX; i++)
        ifact[i] = ifact[i - 1] * inv[i] % mod;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n)
        return 0;
    return (ll)fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll mx = *max_element(vf(v));
    ll N = mx + 1;
    vector<ll> dp(N), facto(N);
    vector<ll> freq(N), f(N);

    for (int i = 0; i < n; i++)
        freq[v[i]]++;

    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            f[i] += freq[j];
        }
    }
    for (int i = mx; i > 0; i--) {
        for (int j = 1; j <= f[i]; j++) {
            dp[i] = (dp[i] + nCr(f[i], j)) % mod;
        }
        for (int j = 2 * i; j <= mx; j += i) {
            dp[i] = (dp[i] - dp[j] + mod) % mod;
        }
    }
    cout << dp[1] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    factorial();
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}