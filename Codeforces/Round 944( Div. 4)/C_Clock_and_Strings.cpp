//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|05|2024 20:42:34            !//
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
    int aa, bb, cc, dd;
    cin >> aa >> bb >> cc >> dd;
    int mx = max({aa, bb, cc, dd}), mn = min({aa, bb, cc, dd});
    int a = min(aa, bb), b = max(aa, bb), c = min(cc, dd), d = max(cc, dd);
    if((a == mn and b == mx) or (c == mn and d == mx))
        cout << "NO" << endl;
    else if(a < c and b < c)
        cout << "NO" << endl;
    else if(c < a and d < a)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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