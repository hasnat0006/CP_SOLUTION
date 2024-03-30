//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|02|2024 21:11:21            !//
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
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    if (k % 2 == 1) {
        int mx = *max_element(vf(v));
        for (int j = 0; j < n; j++) {
            v[j] = mx - v[j];
        }
    }
    else if(k % 2 == 0 and k > 0) {
        int mx = *max_element(vf(v));
        for (int j = 0; j < n; j++) {
            v[j] = mx - v[j];
        }
        mx = *max_element(vf(v));
        for (int j = 0; j < n; j++) {
            v[j] = mx - v[j];
        }
    }
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}