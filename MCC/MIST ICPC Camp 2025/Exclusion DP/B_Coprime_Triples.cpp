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
    facto[3] = 1;
    for (int i = 4; i <= mx; i++) {
        facto[i] = (facto[i - 1] * i) / (i - 3);
    }

    for (int i = mx; i > 0; i--) {
        dp[i] = facto[f[i]];
        for (int j = 2 * i; j <= mx; j += i) {
            dp[i] -= dp[j];
        }
    }
    cout << dp[1] << '\n';
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