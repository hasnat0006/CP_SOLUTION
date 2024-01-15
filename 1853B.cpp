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
#define endl "\n"
const int INFI = 1e18;
const int MOD = 1e9 + 7;
const int N = 45;
vector<int> dp(N, 1);

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != 1)
        return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    // dp[0] = 0;
    // dp[1] = 1;
    fib(40);
    // dbg(dp);
    // cout << dp[40-1] << endl;
    // cin.ignore();
    while (test_case--)
    {
        int nn, kk;
        cin >> nn >> kk;
        if (kk - 2 > 35)
        {
            cout << 0 << endl;
            continue;
        }

        // dbg(nn, kk);
        // int xx = (upper_bound(dp.begin(), dp.end(), nn) - dp.begin());
        // // xx++;
        // int diff = xx - kk + 1;
        // int val_diff = dp[xx] - nn;
        // dbg(xx, diff, val_diff);
        // int ans = (dp[diff] + val_diff);
        // dbg(ans);
        // cout << (ans + 1) / 2 << endl;
        int ans = 0;
        int xx = dp[kk - 3];
        int yy = dp[kk - 2];
        dbg(xx, yy);
        for (int i = 0; i <= nn; i++)
        {
            dbg(nn - yy * i);
            if ((nn - yy * i) >= 0 and (nn - yy * i) % xx == 0)
                if (i >= (nn - yy * i) / xx)
                    ans++;
        }
        cout << ans << endl;
    }
    //! 0 1 2 3 4 5 6 7  8  9  10 11 12  13  14  15   16  17   18   19   20   21    22    23    24    25
    //! 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610  987 1597 2584 4181 6765 10946 17711 28657 46368 75025
    return 0;
}