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

int a, b, c;
int dp[4005];
int final_ans = 0;

int dp_diyei_solve_korbo(int n, int ans) {
    dbg(n, ans);
    if (n == 0) {
        final_ans = max(final_ans, ans);
        return ans;
    }
    if (dp[n] != -1)
        return dp[n];
    int ans1 = 0, ans2 = 0, ans3 = 0;
    if (n >= a)
        ans1 = dp_diyei_solve_korbo(n - a, ans + 1);
    if (n >= b)
        ans2 = dp_diyei_solve_korbo(n - b, ans + 1);
    if (n >= c)
        ans3 = dp_diyei_solve_korbo(n - c, ans + 1);
    dbg(ans1, ans2, ans3, ans, n);
    return dp[n] = max({ans1, ans2, ans3});
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    a = min({x, y, z});
    c = max({x, y, z});
    b = (x + y + z) - a - c;
    cout << dp_diyei_solve_korbo(n, 0) << endl;
    dbg(final_ans);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}