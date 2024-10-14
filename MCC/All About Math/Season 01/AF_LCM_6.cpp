//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|10|2024 20:01:28            !//
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(vf(a));
    int mx = a.back();
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (mx % a[i] != 0) {
            f = 1;
        }
    }
    if (f) {
        cout << n << endl;
        return;
    }
    set<int> divisors;
    for (int i = 2; i * i <= mx; i++) {
        if (mx % i == 0) {
            divisors.insert(i);
            divisors.insert(mx / i);
        }
    }
    int ans = 0;
    for (auto it : divisors) {
        int curLCM = it;
        int len = 0;
        int f = 1;
        vector<int> store;
        for (int i = 0; i < n; i++) {
            if (curLCM == a[i])
                f = 0;
            if (curLCM % a[i] == 0) {
                store.push_back(a[i]);
                len++;
            }
        }
        int lcm = 1;
        for (int i = 0; i < len; i++) {
            lcm = (lcm * store[i]) / __gcd(lcm, store[i]);
        }
        if (f and lcm == curLCM)
            ans = max(ans, len);
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