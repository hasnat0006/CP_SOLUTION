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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int ans = 1, mx = -1, divi = 0;
    for (int i = 0; i < n; i++) {
        ans *= v[i];
        if (ans % k == 0) {
            cout << 0 << endl;
            return;
        }
        mx = max(mx, v[i] % k);
        if (v[i] % 2 == 0)
            divi++;
        dbg(i, divi);
    }
    if (k == 4) {
        if (divi > 0 and n != 1) {
            cout << 1 << endl;
            return;
        }
        int not_divi = n - divi;
        if (not_divi > 1) {
            cout << min(2ll, k - mx) << endl;
            return;
        }
    }
    cout << k - mx << endl;
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