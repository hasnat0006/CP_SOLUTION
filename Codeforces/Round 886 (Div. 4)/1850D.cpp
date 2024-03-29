//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

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
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
const int inf = 2 * 1e5 + 6;
// int dp[inf];

int lis(int i, vector<int> &v, int k)
{
    // if (dp[i] != -1)
    //     return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (v[i] >= v[j] and v[i] - v[j] <= k)
            ans = max(ans, lis(j, v, k) + 1);
    }
    // return dp[i] = ans;
}

void solve()
{
    // memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(vf(v));
    int ans = 0, c = 1;
    // for (int i = 0; i < n; i++)
    //     ans = max(ans, lis(i, v, k));
    dbg(v);
    for (int i = 1; i < n; i++)
    {
        if (v[i] - v[i - 1] <= k)
        {
            c++;
        }
        else
        {
            ans = max(ans, c);
            c = 1;
        }
        dbg(i, c, ans);
    }
    ans = max(ans, c);
    dbg(ans);
    cout << n - ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}