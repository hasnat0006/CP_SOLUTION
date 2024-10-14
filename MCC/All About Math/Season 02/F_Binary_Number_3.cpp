//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|10|2024 00:27:02            !//
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

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;
    int one = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (i >= 0 and s[i - one] == '1') {
            one++;
        }
        if (i - one < 0)
            break;
        swap(s[i], s[i - one]);
        ans.push_back(one);
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i];
        cout << sum << " ";
    }
    while (one--)
        cout << -1 << " ";
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