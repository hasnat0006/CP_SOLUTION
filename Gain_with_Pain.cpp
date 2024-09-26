//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|09|2024 16:02:13            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;

    vector<pair<int, pair<int, int>>> v = {
        {2, {3, 10}}, {2, {3, 10}}, {2, {3, 10}}, {1, {3, 10}}, {3, {3, 10}},
    };
    int f = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int x, y, z;
            cin >> x >> y >> z;
            if(v[j] != make_pair(x, make_pair(y, z))) {
                f = 1;
            }
        }
    }
    cout << (f == 1 ? "Inconsistent" : "Consistent") << endl;
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