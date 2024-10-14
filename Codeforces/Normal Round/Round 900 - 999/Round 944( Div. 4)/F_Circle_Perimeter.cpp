//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|05|2024 21:39:36            !//
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

int countLatticeWITHOUT(int r) {
    int result = 0;
    int x = 1;
    for (int i = r - 1; i >= 1; i--) {
        while (((x * x) + (i * i)) < (r * r)) {
            x++;
            result += i;
        }
    }
    return (result + r - 1) * 4;
}

void solve() {
    int r;
    cin >> r;
    cout << countLatticeWITHOUT(r + 1) - countLatticeWITHOUT(r) << endl;
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