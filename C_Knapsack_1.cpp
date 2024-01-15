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

int dp[105][100005];
int item[2][105];

int ans(int id, int wt)
{
    if (id < 0)
        return 0;
    if (dp[id][wt] != -1)
        return dp[id][wt];
    int take = 0;
    if (wt - item[0][id] >= 0)
        take = item[1][id] + ans(id - 1, wt - item[0][id]);
    int not_take = ans(id - 1, wt);
    return dp[id][wt] = max(take, not_take);
}

void solve()
{
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        item[0][i] = w, item[1][i] = v;
    }
    memset(dp, -1, sizeof dp);
    cout << ans(n - 1, W) << endl;
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