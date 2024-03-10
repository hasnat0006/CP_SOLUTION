//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|03|2024 23:41:36            !//
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

int dp[105][205][205][2];

int f(int ball, int run, int mile, int player){
    
    if(player == 1){
        // captain;
        f(ball - 1, run - 1, mile - 1, 0);
        f(ball - 1, run - 2, mile - 2, 1);
        f(ball - 1, run - 3, mile - 3, 0);
        f(ball - 1, run - 4, mile - 4, 0);
        f(ball - 1, run - 6, mile - 6, 0);

    }
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int x, y, z;
    cin >> x >> y >> z;

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