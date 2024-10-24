//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|10|2024 20:52:51            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll   long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    ll arr[n][n];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll x = i, y = 0;
        ll sum = 0;
        while (x < n && y < n) {
            sum = min(sum, arr[x][y]);
            x++, y++;
        }
        ans += abs(sum);
    }    
    for (ll i = 1; i < n; i++) {
        ll x = 0, y = i;
        ll sum = 0;
        while (x < n && y < n) {
            sum = min(sum, arr[x][y]);
            x++, y++;
        }
        ans += abs(sum);
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