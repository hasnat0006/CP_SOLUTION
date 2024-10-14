//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|04|2024 14:35:27            !//
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

#define mod 1000000007;
#define inf 1000000000000000000;

void solve() {
    int digit, digitSum;
    cin >> digit >> digitSum;
    int COPYdigitSum = digitSum;
    if ((digitSum == 0 and digit != 1) or (digitSum > digit * 9ll)) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    vector<int> ans(digit, 0);
    for (int i = 0; i < digit and digitSum > 0; i++) {
        ans[i] = min(digitSum, 9ll);
        digitSum -= min(digitSum, 9ll);
    }
    vector<int> mn(digit);
    int cnt = digit;
    for (int i = 0; i < digit; i++) {
        cnt--;
        for (int k = 0; k < 10; k++) {
            float baki = (COPYdigitSum - k) / (cnt * 1.0);
            if (cnt == 0) {
                baki = COPYdigitSum;
                mn[i] = baki;
                COPYdigitSum -= baki;
                break;
            }
            dbg(i, k, cnt, COPYdigitSum - k, baki);
            if (baki <= 9.0) {
                mn[i] = k;
                COPYdigitSum -= k;
                break;
            }
        }
        if (i == 0 and mn[i] == 0)
            mn[i] = min(COPYdigitSum, 1ll), COPYdigitSum--;
    }
    for (int i = 0; i < digit; i++)
        cout << mn[i];
    cout << " ";
    for (int i = 0; i < digit; i++)
        cout << ans[i];
    cout << endl;
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