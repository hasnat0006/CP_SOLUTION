//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    set<int> divisor;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }
    int mn = *min_element(vf(v));
    int mx = *max_element(vf(v));
    int ans = mx - mn;
    for (auto &it : divisor) {
        int till = it;
        mn = inf;
        mx = -inf;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            if ((i + 1) % till == 0) {
                mn = min(mn, sum);
                mx = max(mx, sum);
                dbg(it, i, sum);
                sum = 0;
            }
        }
        ans = max(ans, mx - mn);
        dbg(it, mx, mn, mx - mn);
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}