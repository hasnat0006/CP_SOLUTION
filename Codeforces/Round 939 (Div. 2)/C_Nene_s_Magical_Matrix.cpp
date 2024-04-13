//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|04|2024 21:50:46            !//
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

/*
1 1
2 7
3 22
4 50
5 95
6 161
7 252
8 372
9 525
10 715
*/

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << "1 1 1" << endl;
        return;
    }
    int sum = 0, cur = 1;
    for (int i = 1; i <= n; i++, cur += 2) {
        sum += (cur * i);
    }
    int operation = 2 * n;
    cout << sum << " " << operation << endl;
    for (int i = n; i > 0; i--) {
        cout << 2 << " " << i;
        for (int j = 1; j <= n; j++) {
            cout << " " << j;
        }
        cout << endl;
        cout << 1 << " " << i;
        for (int j = 1; j <= n; j++) {
            cout << " " << j;
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