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

int dp[1000005];

int finding_ways(int n){
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    int ans = 0;
    for(int i = 1; i <= 6; i++){
        ans += finding_ways(n - i);
        ans %= mod;
    }
    return dp[n] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << finding_ways(n) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}