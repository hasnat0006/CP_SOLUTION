//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)
// #define ordered_set tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;
const int N = 1e6 + 10;
int dp[N];

int ans(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = 0;
    for (int i = n - 1; i > n - 6; i--)
        dp[n] += ans(i), dp[n] %= mod;
    return dp[n];
}

void solve()
{
    int x;
    // memset(dp, -1, sizeof dp);
    cin >> x;
    // cout << ans(x) << endl;
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int m = i - 1; m >= max((long long)0, i - 6); m--)
        {
            (dp[i] += dp[m]) %= mod;
        }
    }
    cout << dp[x] << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}