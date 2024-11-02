//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|11|2024 20:39:07            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        int type, cost;
        cin >> type >> cost;
        mp[type] += cost;
    }
    vector<int> ans;
    for (auto i : mp) {
        ans.push_back(i.second);
    }
    sort(vf(ans));
    ll sum = 0;
    while (n--) {
        sum += ans.back();
        ans.pop_back();
        if (ans.empty())
            break;
    }
    cout << sum << '\n';
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