//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|02|2024 21:20:27            !//
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
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> one(n + 1, 0), sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        one[i + 1] = one[i];
        sum[i + 1] = sum[i] + v[i];
        if (v[i] == 1)
            one[i + 1]++;
    }
    while (k--) {
        int l, r;
        cin >> l >> r;
        if (l == r)
            cout << "NO" << endl;
        else {
            int one_count = one[r] - one[l - 1];
            int range_sum = sum[r] - sum[l - 1];
            int length = r - l + 1;
            int one_sum = one_count;
            int rem_sum = range_sum - one_count;
            int baki = range_sum - (one_count * 2);
            if (baki >= length - one_count)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
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