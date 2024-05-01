//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|04|2024 22:40:47            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    int CNT = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= n; j += i) {
            int AAAA = j, BBBB = i, GCD = __gcd(AAAA, BBBB);
            if ((AAAA + BBBB) % (BBBB * GCD) == 0)
                CNT++; 
        }
    }
    cout << CNT << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}