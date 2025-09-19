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
    vector<ll> dp(N), cnt(N);
    vector<ll> freq(N), f(N);

    for (int i = 0; i < n; i++)
        freq[v[i]]++;

    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            f[i] += freq[j];
        }
    }
    for (int i = mx; i > 0; i--) {
        dp[i] = (f[i] * (f[i] - 1)) / 2;
        for (int j = 2 * i; j <= mx; j += i) {
            dp[i] -= dp[j];
        }
    }
    for(int i = mx; i > 0; i--) {
        if(dp[i] != 0) {
            cout << i << '\n';
            return;
        }
    }
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