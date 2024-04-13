//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|04|2024 20:39:02            !//
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
    int a, q;
    cin >> a >> q;
    vector<int> v(a);
    for (int &i : v) {
        cin >> i;
    }
    while (q--) {
        int x;
        cin >> x;
        while (1) {
            int id = upper_bound(vf(v), x) - v.begin();
            if(id == 0)
                break;
            x -= id;
        }
        cout << x << " ";
    }
    cout << endl;
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