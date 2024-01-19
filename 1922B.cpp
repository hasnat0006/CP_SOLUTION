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
    int n;
    cin >> n;
    vector<int> v(n), cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    dbg(cnt);
    int smaller = 0, ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += (cnt[i] * (cnt[i] - 1) * (cnt[i] - 2)) / 6;
        ans += (cnt[i] * (cnt[i] - 1)) / 2 * smaller;
        smaller += cnt[i];
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // dbg(i, "-----------");
        solve();
    }
    return 0;
}