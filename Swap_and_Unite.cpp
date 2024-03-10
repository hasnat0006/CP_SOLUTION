//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|03|2024 20:48:50            !//
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
    string s;
    cin >> s;
    map<char, vector<int>> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]].push_back(i);
    }
    int ans = inf;
    for (auto i : mp) {
        if (i.second.size() == 1) {
            ans = 0;
            break;
        }
        int val = i.second.front() + i.second.size();
        int id = lower_bound(vf(i.second), val) - i.second.begin();
        ans = min(ans, (int)i.second.size() - id);
    }
    cout << ans << endl;
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