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
    vector<ll> v(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i + 1];
    
    vector<ll> dp(n + 5, inf);
    ll ans = inf;

    auto cost = [] (vector <ll> a) {
        sort(vf(a));
        return a.back() - a.front();
    };

    for(int cyc = 0; cyc < 4; cyc++) {
        dp[0] = 0, dp[1] = inf;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 2] + cost({v[i], v[i - 1]});
            if(i >= 3)
                dp[i] = min(dp[i], dp[i - 3] + cost({v[i], v[i - 1], v[i - 2]}));
        }
        ans = min(ans, dp[n]);
        for(int i = 2; i <= n; i++) swap(v[i], v[i - 1]);
    }
    cout << ans << '\n';
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