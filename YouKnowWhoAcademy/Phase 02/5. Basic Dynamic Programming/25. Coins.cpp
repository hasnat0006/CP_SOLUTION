//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|11|2024 12:08:58            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n; cin >> n;
    vector<ld> p(n);
    for(auto &i : p)
        cin >> i;
    vector<vector<ld>> dp(n + 1, vector<ld> (n, -1));

    function<ld(ll, ll)> findAns = [&] (ll i, ll head) -> ld {
        if(i < 0)
            return (head > (n - head) ? 1 : 0);
        if(dp[i][head] != -1)
            return dp[i][head];
        ld ans = p[i] * findAns(i - 1, head + 1);
        ans += (1 - p[i]) * findAns(i - 1, head);

        return dp[i][head] = ans;
    };

    cout << fixed << setprecision(10) << findAns(n - 1, 0) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve(); 
    }
    return 0;
}