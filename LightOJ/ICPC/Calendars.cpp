//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|02|2024 20:37:11            !//
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
    int n;
    cin >> n;
    vector<int> v[n + 1];
    vector<int> prefix[n + 1];
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i].push_back(0);
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            v[i].push_back(y);
        }
        prefix[i].resize(x + 1);
        prefix[i][0] = v[i][0];
        for (int j = 1; j <= x; j++) {
            prefix[i][j] = prefix[i][j - 1] + v[i][j];
        }
    }
    int q;
    cin >> q;
    int cnt = 1;
    while (q--) {
        int c1, c2, day, month, year;
        cin >> c1 >> c2 >> day >> month >> year;
        int total = (year - 1) * prefix[c1].back();
        total += prefix[c1][month - 1] + day;
        int ans_year = total / prefix[c2].back();
        total %= prefix[c2].back();
        if (total)
            ans_year++;
        else
            total = prefix[c2].back();
        int id = lower_bound(vf(prefix[c2]), total) - prefix[c2].begin();
        int ans_month = id;
        int ans_day = 0;
        if (id == 1)
            ans_day = total;
        else
            ans_day = total - prefix[c2][id - 1];
        cout << "Query " << cnt++ << ": " << ans_day << " " << ans_month << " " << ans_year << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}