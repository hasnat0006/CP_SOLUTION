//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int   long long
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

int mod  = 1000000007;
float pi = acos(-1);
int inf  = 1e18;

int dp[1001][100001];
int arr[2][100005];

int knapsack(int i, int left){
    if(left == 0)
        return 0;
    if(i < 0)
        return inf;
    if(dp[i][left] != -1)
        return dp[i][left];
    //not choosing
    int x = knapsack(i - 1, left);
    //choosing
    if(left >= arr[1][i])
    x = min(x, knapsack(i - 1, left - arr[1][i]) + arr[0][i]);
    return dp[i][left] = x;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    int n, wt;
    cin >> n >> wt;
    for(int i = 0; i < n; i++)
        cin >> arr[0][i] >> arr[1][i];
    for(int i = 1e5; i >= 0; i--){
        if(knapsack(n - 1, i) <= wt){
            cout << i << endl;
            return;
        }
    }
    
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