//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|06|2024 21:56:34            !//
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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ansA, ansB;
    if (a < x or b < y) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    ansA = x, ansB = y;
    for (int i = 1; ansA <= a and ansB <= b; i++) {
        if (x * i <= a and y * i <= b) {
            ansA = x * i;
            ansB = y * i;
        }
        else
            break;
    }
    cout << ansA << " " << ansB << endl;
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