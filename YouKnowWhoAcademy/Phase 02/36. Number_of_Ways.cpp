//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|10|2024 23:06:13            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

vector<ll> suffix;
ll need;
const int N = 5e5 + 5;
ll dp[N][4];

ll find_way(ll i, ll cnt = 0) {
    if (i == -1)
        return cnt == 3;
    if (dp[i][cnt] != -1)
        return dp[i][cnt];
    ll ans = find_way(i - 1, cnt);
    if (suffix[i] % need == 0) {
        if (suffix[i] == need * (cnt + 1)) {
            if (cnt == 2) {
                if (i == 0)
                    ans += find_way(i - 1, cnt + 1);
            }
            else
                ans += find_way(i - 1, cnt + 1);
        }
    }
    return dp[i][cnt] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll sum = accumulate(vf(v), 0LL);
    if (sum % 3 != 0) {
        cout << 0 << '\n';
        return;
    }
    need = sum / 3;
    ll sum_till_i = 0;
    if (need == 0) {
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            sum_till_i += v[i];
            if (sum_till_i == 0)
                cnt++;
        }
        vector<ll> ans(cnt + 1, 0);
        for (ll i = 3; i <= cnt; i++) {
            ans[i] = i - 2 + ans[i - 1];
        }
        cout << ans[cnt] << '\n';
        return;
    }
    suffix.resize(n);
    suffix[n - 1] = v[n - 1];
    for (ll i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + v[i];
    cout << find_way(n - 1) << '\n';
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