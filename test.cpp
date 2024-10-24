//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|10|2024 23:42:23            !//
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
    ll n, p, q, x, y;
    cin >> n >> p >> q >> x >> y;

    auto sum = [](ll a, ll d, ll n){
        return ((2ll * a + (n - 1) * d) * n )/ 2;
    };
    cout << min(sum(p, -x, n), sum(q, -y, n)) << '\n';
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