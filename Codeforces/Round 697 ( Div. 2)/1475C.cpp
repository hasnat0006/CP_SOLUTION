//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|03|2024 03:20:07            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> boys(a + 1, 0), girls(b + 1, 0);
    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i].first;
        boys[v[i].first]++;
    }
    for (int i = 0; i < k; i++) {
        cin >> v[i].second;
        girls[v[i].second]++;
    }
    int ans = 0;
    for(int i = 0; i < k; i++) {
        int fromB = boys[v[i].first];
        int fromG = girls[v[i].second];
        ans += (k - 1 - (fromB + fromG - (fromB > 0) - (fromG > 0)));
        // cout << i << " " << ans << endl;
    }
    cout << ans / 2 << endl;
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