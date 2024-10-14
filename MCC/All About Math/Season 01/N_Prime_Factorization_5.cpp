//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|06|2024 22:24:53            !//
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
    vector<int> ans;
    ans.push_back(1);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int sz = ans.size();
            while (n % i == 0) {
                int sz1 = ans.size();
                for (int j = sz1 - 1; j >= sz1 - sz; j--) {
                    ans.push_back(ans[j] * i);
                }
                n /= i;
            }
        }
    }
    if (n > 1) {
        int sz = ans.size();
        for (int i = sz - 1; i >= 0; i--) {
            ans.push_back(ans[i] * n);
        }
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << endl;
        solve();
    }
    return 0;
}