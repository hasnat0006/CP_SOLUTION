//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|10|2024 23:54:33            !//
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
    int p, l;
    cin >> p >> l;
    int diff = p - l;
    vector<int> ans;
    for (int i = 1; i * i <= diff; i++) {
        if (diff % i == 0) {
            if (i > l)
                ans.push_back(i);
            if (i != diff / i and (diff / i) > l)
                ans.push_back(diff / i);
        }
    }
    if (ans.empty()) {
        cout << "impossible" << endl;
        return;
    }
    sort(vf(ans));
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}