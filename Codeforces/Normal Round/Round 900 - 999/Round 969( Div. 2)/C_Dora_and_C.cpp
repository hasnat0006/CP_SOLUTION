//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|09|2024 20:38:23            !//
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
    int a, b, n;
    cin >> n >> a >> b;
    int GCD = __gcd(a, b);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= GCD;
    }
    sort(vf(v));
    int ans = v.back() - v.front();
    for(int i = 1; i < n; i++)
        ans = min(ans, v[i - 1] - v[i] + GCD);
    cout << ans << endl;
}

/*
3 2 1 4 5
1 4
3 2 1 4 0
2 3 4
3 2 1 8 0
3 0 3
1 2
3 0 4
1 1

*/

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}