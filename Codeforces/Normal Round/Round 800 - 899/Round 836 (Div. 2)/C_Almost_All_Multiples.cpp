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
    if (n % k) {
        cout << -1 << endl;
        return;
    }
    if (n == k) {
        cout << k << " ";
        for (int i = 2; i < k; i++)
            cout << i << " ";
        cout << 1 << endl;
        return;
    }
    vector<int> ans(n + 1);
    ans[1] = k;
    ans[n] = 1;
    for (int i = 2; i < n; i++)
        ans[i] = i;
    ans[k] = n;
    dbg(ans);
    for (int i = 2; i < n; i++) {
        if (i % k == 0 and n % i == 0) {
            swap(ans[i], ans[k]);
            k = i;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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