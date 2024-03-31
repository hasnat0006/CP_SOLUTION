//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 31|03|2024 21:58:46            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

int dp[1000005];

int COUNT(int n){
    if(n == 0)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    int ans = 0;
    for(int i = 1; i <= 6; i++){
        if(n - i >= 0)
            ans = (ans + COUNT(n - i)) % mod;
    }
    return dp[n] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << COUNT(n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}