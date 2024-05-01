//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|04|2024 20:41:32            !//
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
    cin >> n;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a;
        mp[{min(i, a), max(i, a)}]++;
    }
    for(auto i : mp) {
        if(i.second > 1) {
            cout << "2" << endl;
            return;
        }
    }
    cout << 3 << endl;
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