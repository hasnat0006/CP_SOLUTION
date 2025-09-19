#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
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
        ans = mod_add(ans, dp[i] / i);
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}