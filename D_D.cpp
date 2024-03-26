//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|03|2024 22:32:16            !//
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
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<pair<int, int>> v(k);
    map<pair<int, int>, bool> mp;
    for (int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second;
        mp[{v[i].first, v[i].second}] = true;
    }
    vector<string> ans = {"Carrots", "Kiwis", "Grapes"};
    sort(vf(v));
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        int cnt = (x - 1) * m + y;
        int id = upper_bound(vf(v), make_pair(x, y)) - v.begin();
        if (mp[{x, y}])
            cout << "Waste" << endl;
        else {
            cnt -= (id + 1);
            // cout << cnt << endl;
            cout << ans[cnt % 3] << endl;
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