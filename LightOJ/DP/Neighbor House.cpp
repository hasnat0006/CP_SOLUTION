//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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

int arr[50][3], dp[50][3];

int ans(int i, int j){
    if(i == 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int a = inf, b = inf, c = inf;
    if(j == 0){
        a = arr[i][j] + min(ans(i - 1, 1), ans(i - 1, 2));
    }
    if(j == 1){
        b = arr[i][j] + min(ans(i - 1, 0), ans(i - 1, 2));
    }
    if(j == 2){
        c = arr[i][j] +  min(ans(i - 1, 1), ans(i - 1, 0));
    }
    return dp[i][j] = min({a, b, c});
}

void solve() {
    memset(dp, -1, sizeof dp);
    memset(arr, 0, sizeof arr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout <<  min({ans(n, 0), ans(n, 1), ans(n, 2)}) << endl;
    
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        case(i);
        solve();
    }
    return 0;
}