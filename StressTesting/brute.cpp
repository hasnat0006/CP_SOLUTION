//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|03|2024 00:17:23            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    int xor_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        xor_sum ^= arr[i];
        // debug(xor_sum);
    }
    // debug(xor_sum);
    if (xor_sum == 0) {
        cout << "YES" << endl;
    }
    else {
        int index1 = 0;
        int index2 = n - 1;
        int p = 0;
        int q = 0;
        while (index1 < n) {
            p ^= arr[index1];
            if (p == xor_sum)
                break;
            index1++;
        }
        while (index2 >= 0) {
            q ^= arr[index2];
            if (q == xor_sum)
                break;
            index2--;
        }
        // debug(mp(index1, index2));
        // debug(xor_sum);
        if (index1 < index2 - 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
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