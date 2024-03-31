//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|03|2024 20:39:25            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k != 1 and k != n) {
        cout << -1 << endl;
        return;
    }
    if(k == 1){
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    if(k == n){
        for(int i = 1; i <= n; i++){
            cout << n << " ";
        }
        cout << endl;
    }
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