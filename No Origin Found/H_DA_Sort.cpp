//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 11:38:21            !//
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
    int print, n;
    cin >> print >> n;
    vector<int> v(n), copy(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        copy[i] = v[i];
    }
    sort(vf(v));
    int id = 0;
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (copy[i] == v[id])
            id++, ans--;
    }
    cout << print << " " << ans << endl;
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