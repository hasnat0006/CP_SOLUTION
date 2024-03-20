//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|03|2024 20:42:15            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
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
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    while (1) {
        int f = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < v[i - 1]) {
                int temp = v[i - 1];
                v.erase(v.begin() + i - 1);
                string s = to_string(temp);
                if (s.size() > 1)
                    f = 1;
                for (int j = 0; j < s.size(); j++) {
                    v.insert(v.begin() + i - 1 + j, s[j] - '0');
                }
            }
        }
        if (!f) {
            break;
        }
    }
    if (is_sorted(v.begin(), v.end())) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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