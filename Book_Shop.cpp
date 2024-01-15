//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
// #else 
// #define dbg(x...)
// #define dbgc(x...)
// #endif

using namespace std;

// #define int   long long
#define float long double
#define pb    push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA  cin.tie(NULL), 
#define HASNAT cout.tie(NULL)

// int mod  = 1000000007;
float pi = acos(-1);
// int inf  = 1e18;

int dp[1001][100001];
int book[2][1001];

int ans(int i, int wt){
    if(i < 0 || wt <= 0)
        return 0;
    if(dp[i][wt] != -1)
        return dp[i][wt];
    if(book[0][i] <= wt)
        return dp[i][wt] = max(book[1][i] + ans(i - 1, wt - book[0][i]), ans(i - 1, wt));
    else
        return dp[i][wt] = ans(i - 1, wt);
}

void solve()
{
    int n, wt;
    memset(dp, -1, sizeof(dp));
    cin >> n >> wt;
    for(int i = 0; i < n; i++) // tk
        cin >> book[0][i];
    for(int i = 0; i < n; i++) // page
        cin >> book[1][i];
    cout << ans(n - 1, wt) << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve(); 
    return 0;
}