//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|05|2024 21:29:59            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i + 1];
        // int ans[2][n + 1];
    vector<vector<int>> ans(2, vector<int> (n + 1, 0));
    int odd = 0, even = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] % 2){
            // if i add +1
            ans[0][i] = ans[1][i - 1] + i;
            // no addition
            ans[1][i] = ans[1][i - 1] ;
            ans[1][i] += (ans[1][i - 1] == 0) ? 0 : i - 1;  
            odd = i;
        }
        else{
            even++;
            ans[0][i] = ans[0][i - 1] + i; 
            ans[1][i] = ans[1][i - 1] + i;
        }
    }
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j <= n; j++){
    //         cerr << ans[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    cout << ans[0][n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}