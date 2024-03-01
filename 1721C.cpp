//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|02|2024 11:33:02            !//
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
    int n;
    cin >> n;
    vector<int> a(n), b(n), mn(n), mx(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) {
        int id = lower_bound(vf(b), a[i]) - b.begin();
        mn[i] = b[id] - a[i];
    }
    int till = n;
    for (int i = n - 1; i >= 0; i--) {
        int id = lower_bound(b.begin(), b.begin() + n, a[i]) - b.begin();
        mx[i] = b[till - 1] - a[i];
        if (id == i)
            till = i;
    }
    for (int i = 0; i < n; i++)
        cout << mn[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << mx[i] << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}