//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|05|2024 20:45:52            !//
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
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        cin >> b[i];
    int ans = 0, last = b.back(), f = 0, mn = inf, mx = -inf;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        c.push_back(a[i]);
        c.push_back(b[i]);
        ans += abs(a[i] - b[i]);
        mn = min({mn, a[i], b[i]});
        mx = max({mx, a[i], b[i]});
        if (min(a[i], b[i]) <= last && last <= max(a[i], b[i]))
            f = 1;
    }
    c.push_back(last);
    if(f){
        cout << ans + 1 << endl;
        return;
    }
    // cout << ans << " " << mn << " " << mx << " " << last << endl;
    if(last < mn)
        ans += (mn - last) + 1;
    else if(last > mx)
        ans += (last - mx) + 1;
    else{
        sort(vf(c));
        int id = lower_bound(vf(c), last) - c.begin();
        int x = c[id - 1], y = c[id + 1];
        ans += min(abs(x - last), abs(y - last)) + 1;
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