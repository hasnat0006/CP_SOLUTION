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
int inf = 1e18;

void solve()
{
    char arr[8][8];
    string ans = "";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> arr[i][j];
        }
    }
    // for (int i = 0; i < 0; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[j][i] != '.')
                ans.pb(arr[j][i]);
        }
    }
    cout << ans << endl;
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