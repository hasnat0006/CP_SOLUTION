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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, x;
    cin >> n;
    vector<int> v(n + 1);
    map<int, int> count;
    vector<int> diff(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int cnt = 0, c = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i] != v[i - 1])
            cnt = i - 1, c = 0;
        else
            c++;
        // dbg(i, cnt, c);
        diff[i] = cnt;
    }
    // dbg(diff);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // dbg(l, r, diff[r]);
        if (diff[r] >= l and v[diff[r]] != v[r]) {
            cout << diff[r] << " " << r << endl;
        }
        else {
            cout << -1 << " " << -1 << endl;
        }
    }
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}