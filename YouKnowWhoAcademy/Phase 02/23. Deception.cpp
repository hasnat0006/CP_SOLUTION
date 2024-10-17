//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|10|2024 19:15:08            !//
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
    float x, y;
    cin >> x >> y;

    // log b (A ^ x) = x log b A    
    // x ^ y = log (x ^ y) = y log x

    float num1 = y * log10l(x);
    float num2 = x * log10l(y);

    if(num1 == num2)
        cout << '=' << endl;
    else
        cout << (num1 > num2 ? '>' : '<') << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}