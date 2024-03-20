//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|03|2024 01:18:14            !//
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
    int n, m, temp;
    cin >> n >> m;
    map<int, vector<int>> x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            x[temp].push_back(i);
            y[temp].push_back(j);
        }
    }

    auto SUM = [&](auto a) {
        int ans = 0;
        for (auto &i : a) {
            int pre = 0, suf = 0;
            sort(vf(i.second));
            for (int j = 0; j < i.second.size(); j++) {
                ans += (i.second[j] * j) - pre;
                ans += suf - (i.second[j] * j);
                pre += i.second[j];
                suf += i.second[i.second.size() - j - 1];
            }
        }
        return ans;
    };

    cout << SUM(x) + SUM(y) << endl;
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